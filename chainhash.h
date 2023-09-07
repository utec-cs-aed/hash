#include <vector>
#include <forward_list>

using namespace std;

const int maxColision = 3;
const float maxFillFactor = 0.5;

template<typename TK, typename TV>
class ChainHash
{
private:    
    struct Entry{
		TK key;
		TV value;
		size_t hashcode;		
	} 
	forward_list<Entry> *array;//array de listas enlazadas
	int capacity;//tamanio del array
    int size;//cantidad de elementos totales

public:
    ChainHash(int _cap = 10){
		// TODO: asignar un tamanio inicial al array
		capacity = _cap; 
		array = new list<Entry>[capacity];
		size = 0;
	}

	void insert(TK key, TV value){
		if(fillFactor() >= maxFillFactor) rehashing();
		size_t hashcode = getHashCode(key);
		int index = hashcode % capacity;
		//TODO: insertar el Entry(key, value) en array[index] verificando si la key ya existe
		
	}

	TV find(TK key);

	void remove(TK key);

	//TODO: implementar el operador corchete [ ]

private:
	double fillFactor(){
		return size / (capacity * maxColision);
	}

	size_t getHashCode(TK key){
		std::hash<TK> ptr_hash;
		return ptr_hash(key);
	}

	void rehashing();	
};

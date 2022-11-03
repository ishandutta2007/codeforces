#include <cstdio>
#include <map>
#include <utility>

typedef std::multimap<unsigned, unsigned> container_type; //<height, mass>

unsigned jump_h;
unsigned max_candies;
container_type fruit1, caramel1, fruit2, caramel2;

void read() {
	unsigned N, t, h, m;
	
	scanf("%u%u", &N, &jump_h);
	while(N-- > 0) {
		scanf("%u%u%u", &t, &h, &m);
		if(t == 0) {
			caramel1.insert(std::make_pair(h, m));
		}
		else {
			fruit1.insert(std::make_pair(h, m));
		}
	}
	
	fruit2 = fruit1;
	caramel2 = caramel1;
}

void write() {
	printf("%u", max_candies);
}

unsigned solve(bool first_type) {
	unsigned candies = 0;
	unsigned new_jump_h = jump_h;
	bool last_type = !first_type;
	container_type * current;
	container_type::iterator heaviest;
	while(true) {
		if(last_type == 0) {
			current = (first_type) ? (&fruit1) : (&fruit2);
		}
		else {
			current = (first_type) ? (&caramel1) : (&caramel2);
		}
		
		heaviest = current->end();
		for(container_type::iterator it = current->begin(); it != current->end() && it->first <= new_jump_h; ++it) {
			if(heaviest == current->end() || it->second > heaviest->second)
				heaviest = it;
		}
		if(heaviest == current->end())
			break;
		
		new_jump_h += heaviest->second;
		current->erase(heaviest);
		last_type = !last_type;
		++candies;
	}
	
	return candies;
}

int main() {
	unsigned c;
	read();
	c = solve(0);
	max_candies = solve(1);
	if(c > max_candies) max_candies = c;
	write();
}
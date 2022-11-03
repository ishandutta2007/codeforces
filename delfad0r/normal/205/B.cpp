#include <iomanip>
#include <iostream>

int N;
long long increment;

int main() {
	int k, last = 0;
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> N;
	while(--N >= 0) {
		std::cin >> k;
		if(k < last) {
			increment += last - k;
		}
		last = k;
	}
	
	std::cout << increment;
	
	return 0;
}
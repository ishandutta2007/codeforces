#include <iostream>

int N;
int min_t = 1000000001;
int nearest_city;
bool still_rodzil = false;

int main() {
	int t;
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> N;
	for(int i = 1; i <= N; ++i) {
		std::cin >> t;
		if(t == min_t) {
			still_rodzil = true;
			if(min_t == 1)
				break;
		}
		if(t < min_t) {
			min_t = t;
			nearest_city = i;
			still_rodzil = false;
		}
	}
	
	if(still_rodzil)
		std::cout << "Still Rozdil";
	else
		std::cout << nearest_city;
		
	return 0;
}
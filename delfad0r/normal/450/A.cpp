#include <algorithm>
#include <iostream>
#include <utility>

typedef std::pair<int, int> intint;

int N, M;
intint candies[101];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M;
	for(int n = 1; n <= N; ++n) {
		candies[n].second = n;
		std::cin >> candies[n].first;
		candies[n].first = (candies[n].first - 1) / M + 1;
	}
	
	std::sort(candies + 1, candies + N + 1);
	
	std::cout << candies[N].second;
}
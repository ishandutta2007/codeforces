#include <cstdio>
#include <iostream>
#include <set>

int N, M;
std::set<int> differences;

int main() {
	std::ios_base::sync_with_stdio(false);
	char str[1001];
	int G_pos;
	std::cin >> N >> M;
	for(int n = 0; n < N; ++n) {
		std::cin >> str;
		G_pos = -1;
		for(int m = 0; m < M; ++m) {
			if(str[m] == 'G') {
				G_pos = m;
			}
			else if(str[m] == 'S') {
				if(G_pos < 0) {
					std::cout << "-1";
					return 0;
				}
				differences.insert(m - G_pos);
				break;
			}
		}
	}
	
	printf("%lu", differences.size());
}
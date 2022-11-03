#include <bitset>
#include <cstdio>
#include <iostream>

int N;
char str[13];
std::bitset<12> cols[6][12];
int divisors[] = {1, 2, 3, 4, 6, 12};

void init() {
	for(int i = 0; i < 6; ++i) {
		for(int x = 0; x < 12 / divisors[i]; ++x) {
			for(int y = x; y < 12; y += 12 / divisors[i]) {
				cols[i][x][y] = 1;
			}
		}
	}
}

void solve() {
	int count = 0;
	std::bitset<6> is_solution;
	
	std::bitset<12> curr;
	for(int i = 0; i < 12; ++i) {
		if(str[i] == 'X') curr[i] = 1;
		else curr[i] = false;
	}
	
	for(int i = 0; i < 6; ++i) {
		for(int c = 0; c < 12 / divisors[i]; ++c) { 
			if((curr & cols[i][c]) == cols[i][c]) {
				++count;
				is_solution[i] = true;
				break;
			}
		}
	}
	
	std::cout << count;
	for(int i = 0; i < 6; ++i)
		if(is_solution[i])
			std::cout << ' ' << divisors[i] << 'x' << 12 / divisors[i];
	std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	init();
	
	std::cin >> N;
	while(--N >= 0) {
		std::cin >> str;
		solve();
	}
}
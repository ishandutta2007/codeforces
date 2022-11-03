#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>

int N;
int A[101];
int memo[101][1 << 16];
int prev[101][1 << 16], val[101][1 << 16];
int primes[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
unsigned factors[60];

void find_factors() {
	for(int i = 1; i < 60; ++i) {
		for(int p = 0; p < 16; ++p)
			if(i % primes[p] == 0) factors[i] |= 1 << p;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	for(int n = 1; n <= N; ++n)
		std::cin >> A[n];
	
	find_factors();
	memset(memo, 255, sizeof(memo));
	memset(memo[0], 0, sizeof(memo[0]));
	
	for(int n = 1; n <= N; ++n) {
		for(int i = 1; i < 59; ++i) {
			unsigned invf = ~factors[i] & ((1 << 16) - 1);
			for(unsigned mask = invf; ; mask = (mask - 1) & invf) {
				if(memo[n - 1][mask] != -1) {
					if(memo[n][factors[i] | mask] == -1 ||
						memo[n][factors[i] | mask] > memo[n - 1][mask] + abs(i - A[n])) {
							memo[n][factors[i] | mask] = memo[n - 1][mask] + abs(i - A[n]);
							val[n][factors[i] | mask] = i;
							prev[n][factors[i] | mask] = mask;
					}
				}
				if(mask == 0) break;
			}
		}
	}
	
	std::stack<int> ans;
	int n = std::min_element(memo[N], memo[N] + (1 << 16)) - memo[N];
	for(int i = N; i > 0; --i) {
		ans.push(val[i][n]);
		n = prev[i][n];
	}
	while(!ans.empty()) {
		std::cout << ans.top() << ' ';
		ans.pop();
	}
}
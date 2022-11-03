#include <bitset>
#include <iostream>

int N, M;
long long pow2[17];
std::bitset<17> A[100002];	//length = 10^5 + 2, so A[0] = A[100001] = 0
long long S;

void init() {
	for(int b = 0; b < 17; ++b)
		pow2[b] = 1 << b;
}

void read() {
	unsigned a;
	std::cin >> N >> M;
	for(int n = 1; n <= N; ++n) {
		std::cin >> a;
		A[n] = a;
	}
}

void init_sum() {
	long long len;
	for(int b = 0; b < 17; ++b) {
		len = 0;
		for(int n = 1; n <= N; ++n) {
			if(A[n][b]) {
				++len;
			}
			else if(len > 0) {
				S += pow2[b] * (len * (len + 1) / 2);
				len = 0;
			}
		}
		if(len > 0)
			S += pow2[b] * (len * (len + 1) / 2);
	}
}

void change_element(int pos, int val) {
	for(int b = 0; b < 17; ++b) {
		if(A[pos][b] == bool(val & pow2[b]))
			continue;
		long long l = pos, r = pos;
		while(A[l - 1][b])
			--l;
		while(A[r + 1][b])
			++r;
		if(val & pow2[b])
			S += pow2[b] * (pos - l + 1) * (r - pos + 1);
		else
			S -= pow2[b] * (pos - l + 1) * (r - pos + 1);
	}
	A[pos] = val;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	init();
	
	read();
	
	init_sum();
	
	int p, v;
	for(int m = 0; m < M; ++m) {
		std::cin >> p >> v;
		change_element(p, v);
		std::cout << S << '\n';
	}
}
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int N, K, X;
bitset<32> A[200200];
int bits[64];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K >> X;
	for(int n = 0; n < N; ++n) {
		unsigned a;
		cin >> a;
		A[n] = bitset<32>(a);
		for(int i = 0; i < 32; ++i)
			if(A[n][i]) ++bits[i];
	}
	
	ull Y = 1;
	while(K--) Y *= X;
	
	ull ans = 0;
	for(int n = 0; n < N; ++n) {
		for(int i = 0; i < 32; ++i)
			if(A[n][i]) --bits[i];
		bitset<64> B(Y * A[n].to_ulong());
		bitset<64> tmpans;
		for(int i = 0; i < 64; ++i)
			if(bits[i] || B[i]) tmpans[i] = 1;
		ans = max(ans, tmpans.to_ullong());
		for(int i = 0; i < 32; ++i)
			if(A[n][i]) ++bits[i];
	}
	
	cout << ans << '\n';
}
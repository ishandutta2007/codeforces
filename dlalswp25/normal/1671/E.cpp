#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> piii;

const ll MOD = 998244353;

int N;
char A[262626];
ll D[262626];
int H[262626];

int main() {
	scanf("%d", &N);
	scanf("%s", A + 1);
	for(int i = 1 << N - 1; i < 1 << N; i++) {
		D[i] = 1;
		H[i] = (A[i] == 'A');
	}

	for(int i = N - 2; i >= 0; i--) {
		map<piii, int> mp;
		int h = 0;
		for(int j = 1 << i; j < 1 << i + 1; j++) {
			int hl = H[j << 1], hr = H[j << 1 | 1];
			if(hl == hr) D[j] = D[j << 1] * D[j << 1] % MOD;
			else D[j] = 2 * D[j << 1] * D[j << 1 | 1] % MOD;
			piii x = piii(A[j] == 'A' ? 1 : 0, min(hl, hr), max(hl, hr));
			if(mp.find(x) == mp.end()) {
				H[j] = mp[x] = h; h++;
			}
			else H[j] = mp[x];
		}
	}
	printf("%lld\n", D[1]);
	return 0;
}
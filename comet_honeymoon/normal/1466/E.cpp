#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, n;
int cnt[60];
int A[500005];

const int p = 1000000007;

signed main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		for(int i = 0; i < 60; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &A[i]);
			for(int j = 0; j < 60; j++) cnt[j] += 1 & (A[i] >> j);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int tmp1 = 0, tmp2 = 0;
			for(int j = 0; j < 60; j++) if((A[i] >> j) & 1) tmp1 = (tmp1 + (1LL << j) % p * cnt[j] % p) % p;
			for(int j = 0; j < 60; j++)
				if((A[i] >> j) & 1) tmp2 = (tmp2 + (1LL << j) % p * n % p) % p;
				else tmp2 = (tmp2 + (1LL << j) % p * cnt[j] % p) % p;
			ans = (ans + tmp1 * tmp2 % p) % p;
		}
		printf("%lld\n", ans);
	}
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[70];
int N, M;

map<ll, int> mp;

ll toint() {
	ll ret = 0;
	for(int i = 0; i < M; i++) {
		if(s[i] == '1') ret += (1LL << M - i - 1);
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		mp.clear();
		scanf("%d%d", &N, &M);
		ll x = (1LL << M - 1) - 1;
		int f = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%s", s);
			ll y = toint();
			if(f) {
				if(x <= y) {
					do {
						x--;
					}while(mp[x]);
				}
			}
			else {
				if(x >= y) {
					do {
						x++;
					}while(mp[x]);
				}
			}

			f = !f;
			mp[y] = 1;
			// printf("%lld %lld\n", y, x);
		}

		for(int i = 0; i < M; i++) {
			printf("%d", ((1LL << M - i - 1) & x) > 0);
		}
		puts("");
	}
	return 0;
}
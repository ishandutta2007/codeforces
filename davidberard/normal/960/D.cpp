#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	vector<ll> shift(64, 0);
	for(int qq=0;qq<Q;++qq) {
		int type; ll x; cin >> type; cin >> x;
		int level = 64 - __builtin_clzll(x);
		if(type < 3) {
			ll k; cin >> k;
			if(type == 1) {
				shift[level] = (shift[level] + k + (1LL<<(level-1)))%(1LL<<(level-1));
			} else {
				int lvl = level;
				ll amt = k;
				for(;lvl<61;amt<<=1, lvl++) {
					shift[lvl] = (shift[lvl] + amt + (1LL<<(lvl-1)))%(1LL<<(lvl-1));
				}
			}
		} else { // type == 3: 
			int lev = level;
			ll pos = (x+shift[lev])%(1LL<<(lev-1)) + (1LL<<(lev-1));
			while(pos > 0) {
				printf("%I64d ", (pos-shift[lev])%(1LL<<(lev-1)) + (1LL<<(lev-1)));
				pos>>=1;
				--lev;
			}
			printf("\n");
		}
	}
	return 0;
}
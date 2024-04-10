#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ n, x, tc;
multiset<_> ms;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		ms.clear();
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &x);
			ms.insert(x);
		}
		bool ok = true;
		for(_ i = n; i >= 1; --i) {
			for(; *ms.rbegin() != i; ) {
				if(*ms.rbegin() < i) {
					ok = false;
					break;
				}
				_ x = *ms.rbegin();
				ms.erase(ms.find(x));
				ms.insert(x>>1);
			}
			if(!ok) break;
			ms.erase(ms.find(i));
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}
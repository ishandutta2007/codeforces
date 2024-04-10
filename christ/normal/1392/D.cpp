#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5 + 5, MOD = 1e9 + 7;
char s[MN];
void solve () {
	int n;
	scanf ("%d",&n);
	bool same = 1;
	scanf ("%s",s+1);
	for (int i = 2; i <= n; i++) same &= s[i] == s[1];
	if (same) return (void) printf ("%d\n",(n + 2) / 3);
	int st = -1;
	for (int i = 1; i <= n; i++) if (s[i] != s[1]) {st=i;break;}
	char cur = '0'; int sz = 0; ll ret = 0;
	for (int i = st; i <= n; i++) {
		if (s[i] != cur) {
			ret += sz / 3;
			sz = 0;
		}
		++sz; cur = s[i];
	}
	for (int i = 1; i < st; i++) {
		if (s[i] != cur) {
			ret += sz / 3;
			sz = 0;
		}
		++sz; cur = s[i];
	}
	ret += sz/3;
	printf ("%lld\n",ret);
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
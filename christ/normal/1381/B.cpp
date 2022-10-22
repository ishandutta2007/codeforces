#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define setio(x) freopen(x ".in","r",stdin); freopen(x ".out","w",stdout)
const int MN = 1e5 + 2, LOG = 17, INF = 1e8, MOD = 998244353, BASE = 131;
void solve () {
	int n;
	scanf ("%d",&n); n<<=1;
	vector<bool> poss(n+1); poss[0] = 1; vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	int lst = n + 1, mx = n; set<int> has; for (int i = 1; i <= n; i++) has.insert(i);
	for (int i = n; i >= 1; i--) {
		if (a[i] == mx) {
			int sz = lst - i;
			lst = i;
			for (int j = n; j >= sz; j--) poss[j] = poss[j] | poss[j-sz];
			has.erase(a[i]);
			if (i != 1) mx = *has.rbegin();
		}
		else has.erase(a[i]);
	}
	printf (poss[n/2] ? "YES\n" : "NO\n");
}
int main () {
	int tt;
	scanf ("%d",&tt);
	while (tt--) solve();
	return 0;
}
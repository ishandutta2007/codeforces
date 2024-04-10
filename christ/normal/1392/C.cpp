#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5 + 5, MOD = 1e9 + 7;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n), need(n);
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		if (i) ret += max(0,a[i-1]-a[i]);
	}
	printf ("%lld\n",ret);
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
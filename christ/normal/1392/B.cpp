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
	int n; ll k;
	scanf ("%d %lld",&n,&k);
	vector<int> a(n); int mx = -1e9;;
	for (auto &au : a) scanf ("%d",&au), mx = max(mx,au);
	--k;
	for (auto &au : a) au = mx - au;
	if (k&1) {
		mx=-1e9;
		for (auto &au : a) mx = max(mx,au);
		for (auto &au : a) au = mx - au;
	}
	for (auto &au : a) printf ("%d ",au);
	printf ("\n");
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, LOG = 18, MOD = 1e9+7;
int main() {
	int n;
	scanf ("%d",&n);
	vector<ll> b(n);
	for (auto &au : b) scanf ("%lld",&au);
	vector<ll> a(n);
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		a[i] = mx + b[i];
		mx = max(mx,a[i]);
		printf ("%d ",a[i]);
	}
	printf ("\n");
    return 0;
}
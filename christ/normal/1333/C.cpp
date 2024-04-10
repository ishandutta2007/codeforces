#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e5+3, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1);
	vector<ll> psa(n+1); map<ll,int> go;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		psa[i] += psa[i-1];
		psa[i] += a[i]; 
	}
	ll ret = 0; int l = 1; go[0] = 0; 
	for (int i = 1; i <= n; i++) {
		if (go.count(psa[i])) l = max(l,go[psa[i]]+2); 
		ret += i-l+1;
		go[psa[i]] = i;
	}
	printf ("%lld\n",ret);
    return 0;
}
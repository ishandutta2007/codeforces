#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, LOG = 18, MOD = 1e9+7;
const double EPS = 1e-15;
ll rbit[MN], lbit[MN];
vector<int> xs;
int getx (int x) {return lower_bound(all(xs),x)-xs.begin()+1;}
void update (ll *bit, int i, int v) {
	for (;i<MN;i+=i&-i)
		bit[i] += v;
} 
int query (ll *bit, int i) {
	ll ret = 0;
	for (;i;i^=i&-i)
		ret += bit[i];
	return ret%MOD;
}
void uadd (int &a, int b) {a += b; if (a >= MOD) a -= MOD;}
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), xs.push_back(a[i]);
	sort(all(xs));
	int ret = 0;
	for (int i = 1; i <= n; i++) update(rbit,getx(a[i]),n-i+1);
	for (int i = 1; i <= n; i++) {
		uadd(ret,(ll)i*(n-i+1)%MOD*a[i]%MOD);
		update(rbit,getx(a[i]),i-n-1);
		uadd(ret,(ll)query(lbit,getx(a[i]))*(n-i+1)%MOD*a[i]%MOD);
		uadd(ret,(ll)query(rbit,getx(a[i]))*i%MOD*a[i]%MOD);
		update(lbit,getx(a[i]),i);
	}
	printf ("%d\n",ret);
    return 0;
}
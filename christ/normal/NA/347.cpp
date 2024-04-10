#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+3;
struct Line {
	ll m,b;
	ll get (ll x) {return m*x+b;}
	double intersect (const Line &o) {return (b-o.b)/double(o.m-m);}
} lines[MN];
int main () {
	int n;
	scanf ("%d",&n);
	vector<int> b(n+1), a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), --a[i];
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]);
	int l = 0, r = 1;
	lines[0] = {b[1],b[1]};
	for (int i = 2; i <= n; i++) {
		while (r-l>1&&lines[l].get(a[i])>lines[l+1].get(a[i]))
			++l;
		ll dp = lines[l].get(a[i])+b[i];
		if (i == n) return !printf ("%lld\n",dp);
		Line nline = {b[i],dp};
		while (r-l>1&&nline.intersect(lines[r-1])<lines[r-1].intersect(lines[r-2]))
			--r;
		lines[r++] = nline;
	}
	return 0;
}
//dp[i] = min(dp[j]+b[j]*a[i]+b[i])
//m = b[j], b = dp[j]
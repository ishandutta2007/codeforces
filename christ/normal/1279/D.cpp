#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+5, LOG = 60, MOD = 998244353, ADD = 9;
using pii = pair<int,int>;
using ll = long long;
vector<int> p[MN];
int k[MN];
int cnt[MN];
int fpow (int base, int ex) {int res = 1;while (ex) {if (ex&1) res = res*1LL*base%MOD;base = base*1LL*base%MOD;ex>>=1;}return res;}
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
int moddiv (int a, int b) {return a*1LL*fpow(b,MOD-2)%MOD;}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&k[i]);
		for (int j = 0; j < k[i]; j++) {
			int a;
			scanf ("%d",&a);
			p[i].push_back(a);
			cnt[a]++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll frac = moddiv(1,n*1LL*k[i]%MOD);
		for (int a : p[i]) {
			ans = (ans + frac * moddiv(cnt[a],n))%MOD;
		}
	}
	printf ("%lld\n",ans);
	return 0;
}
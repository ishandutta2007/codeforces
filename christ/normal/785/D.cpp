#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
const int MN = 2e5+3, BASE = 31, LOG = 20, MOD = 1e9+7;
int pw[MN], fac[MN], invfac[MN], rgt[MN], dfac[MN]; char s[MN];
int madd (int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}
int inv (int base) {
	int res = 1, exp = MOD-2;
	while (exp) {
		if (exp&1) res = res*1LL*base%MOD;
		base = base*1LL*base%MOD;
		exp>>=1;	
	}
	return res;
} 
int choose (int n, int k) {
	return fac[n]*1LL*invfac[k]%MOD*invfac[n-k]%MOD;
}
int main() {
	scanf ("%s",s+1);
	int n = strlen(s+1), cnt = 0, ans = 0;
	pw[0] = fac[0] = invfac[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = madd(pw[i-1],pw[i-1]), fac[i]=fac[i-1]*1LL*i%MOD, invfac[i]=inv(fac[i]);
	for (int i = 1; i <= n; i+=2) dfac[i] = (i==1?1:dfac[i-2])*1LL*i%MOD;
	for (int i = n; i >= 1; i--) rgt[i] = rgt[i+1] + (s[i] == ')');
	for (int i = 1; i <= n; i++) if (s[i] == '('){
		int c1 = ++cnt, c2 = rgt[i];
		ans += choose(c1+c2-1,c1);
		ans %= MOD;
	}
	printf ("%d\n",ans);
	return 0;
}
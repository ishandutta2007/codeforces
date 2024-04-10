//Code By CXY07
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAXN = 2e6 + 10;
const int INF = 2e9;
const int mod = 998244353;
 
int D,q,u,v,gcd;
int a[MAXN],s[MAXN],cnt;
int fac[MAXN];
 
int GCD(int x,int y) {
	if(!y) return x;
	return GCD(y,x % y);
}
 
inline int ksm(int x,int b) {
	int res = 1;
	while(b) {
		if(b & 1) (res *= x) %= mod;
		b >>= 1;
		(x *= x) %= mod;
	}
	return res;
}
 
signed main () {
	scanf("%lld%lld",&D,&q);
	int dd = D;
	for(register int i = 2;i * i <= dd; ++i) {
		if(D % i) continue;
		a[++cnt] = i;
		while(D % i == 0) s[cnt]++,D /= i;
	}
	if(D != 1) a[++cnt] = D,s[cnt] = 1;
	fac[0] = 1;
	for(register int i = 1;i <= (int)2e6; ++i)
		fac[i] = (fac[i - 1] * i) % mod;
	while(q--) {
		scanf("%lld%lld",&u,&v);
		if(u == v) {puts("1"); continue;}
		gcd = GCD(u,v);
		u /= gcd,v /= gcd;
		int cntu = 0,cntv = 0,tmpu = 1,tmpv = 1;
		for(register int i = 1,tmp;i <= cnt; ++i) {
			tmp = 0;
			if(a[i] > u) break;
			while(u % a[i] == 0) tmp++,u /= a[i];
			(tmpu *= fac[tmp]) %= mod;
			cntu += tmp;
		}
		for(register int i = 1,tmp;i <= cnt; ++i) {
			tmp = 0;
			if(a[i] > v) break;
			while(v % a[i] == 0) tmp++,v /= a[i];
			(tmpv *= fac[tmp]) %= mod;
			cntv += tmp;
		}
		printf("%lld\n",(fac[cntu] * fac[cntv]) % mod * ksm(tmpu,mod - 2) % mod * ksm(tmpv,mod - 2) % mod);
	}
	return 0;
}
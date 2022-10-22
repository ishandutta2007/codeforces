#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
ll fpow (ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp&1) ret = ret*base%MOD;
		base=base*base%MOD;
		exp>>=1;
	}
	return ret;
}
int main () { 
	int n; scanf ("%d",&n);
	int good = 0, bad = 0;
	for (int i = 1;i<=3;i++)
		for (int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				if (i+j+k!=6)
					++good;
				else
					++bad;
	ll ret = 0, fail = 1;
	for (int i = 0; i < n; i++) {
		ret += good * fail % MOD * fpow(3,3*(n-1-i)) % MOD;
		ret %= MOD;
		fail = (fail * 1LL * bad) % MOD;
	}
	printf ("%lld\n",ret);
	return 0;
}
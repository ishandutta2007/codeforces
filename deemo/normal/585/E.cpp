#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;
const int MAXVAL = 1e7 + 10;
const int MOD = 1e9 + 7;

int n, val[MAXN];
bool pr[MAXVAL + 5];
int mn[MAXVAL + 5], cc[MAXVAL + 5], gg[MAXVAL + 5];
int sec[MAXN];
ll ss[MAXN], tt[MAXN + 5];

int main(){
	for (int i = 2; i < MAXVAL; i++)
		if (!pr[i])
			for (int j = i; j < MAXVAL; j += i)
				mn[j] = mn[j]?mn[j]:i, pr[j] = 1;
	for (int i = 2; i < MAXVAL; i++)
		cc[i] = (mn[i/mn[i]]==mn[i]?0:1) + cc[i/mn[i]];

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		int t = 0, temp = val[i];
		while (temp - 1){
			if (!t || sec[t - 1] ^ mn[temp])
				sec[t++] = mn[temp];
			temp /= mn[temp];
		}
		
		ss[0] = 1;
		for (int ms = 1; ms < (1<<t); ms++){
			ss[ms] = ss[ms^(ms&-ms)] * sec[__builtin_ctz(ms&-ms)];
			gg[ss[ms]]++;
		}
	}

	tt[0] = 1;
	for (int i = 1; i < MAXN; i++)
		tt[i] = tt[i-1]*2ll%MOD;
	ll cnt = 0;
	for (int i = 2; i < MAXVAL; i++)
		if (cc[i]&1)
			cnt = (cnt + (tt[gg[i]] - 1 + MOD)) % MOD; 
		else
			cnt = (cnt + MOD - (tt[gg[i]] - 1 + MOD)) % MOD;

	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll ret = 0;
		int t = 0, temp = val[i];
		while (temp - 1){
			if (!t || sec[t - 1] ^ mn[temp])
				sec[t++] = mn[temp];
			temp /= mn[temp];
		}

		ss[0] = 1;
		for (int ms = 1; ms < (1<<t); ms++){
			ss[ms] = ss[ms^(ms&-ms)] * sec[__builtin_ctz(ms&-ms)];
			if (cc[ss[ms]] & 1)
				ret = (ret + (tt[gg[ss[ms]]] - 1 + MOD)) % MOD;
			else
				ret = (ret + MOD - (tt[gg[ss[ms]]] - 1 + MOD)) % MOD;
		}

		ans = (ans + cnt + MOD - ret) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}
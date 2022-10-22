#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;
const int C = 6;

int c[2][MAXN], d[2][MAXN], e[2][MAXN], ss[MAXN], f[7][MAXN], pp[20];

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a % MOD;
	}
	return ret;
}

int main(){
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++){
		ss[i] = ss[i - 1] + ss[i - 1];
		while (ss[i] >= MOD) ss[i] -= MOD;
	}
	{
		int n;	scanf("%d", &n);
		while (n--){
			int x; scanf("%d", &x);

			e[0][x] = (1ll*ss[1]*e[0][x]%MOD + 1ll*ss[c[0][x]]*(1ll*x*x%MOD) + 2ll*d[0][x]*x) % MOD;
			d[0][x] = (1ll*ss[1]*d[0][x] + 1ll*ss[c[0][x]]*x) % MOD;
			c[0][x]++;
		}
	}

	bool cur = 0;
	for (int w = 0; w < C; w++, cur = !cur){
		for (int i = 0; i < MAXN; i++)
			c[!cur][i] = d[!cur][i] = e[!cur][i] = 0;

		int temp = 1;
		for (int i = 0; i < w; i++) temp *= 10;

		for (int i = 0; i < MAXN; i++){
			int t = i, rem = i/temp%10;
			for (; ~rem; rem--, t -= temp){
				e[!cur][t] = (1ll*ss[c[cur][i]]*e[!cur][t]%MOD + 1ll*ss[c[!cur][t]]*e[cur][i]%MOD + 2ll*d[!cur][t]*d[cur][i])%MOD;
				d[!cur][t] = (1ll*ss[c[cur][i]]*d[!cur][t] + 1ll*ss[c[!cur][t]]*d[cur][i]) % MOD;
				c[!cur][t] += c[cur][i];
			}
		}
	}

	pp[0] = 1;
	for (int i = 1; i < 7; i++)
		pp[i] = pp[i - 1] * 10;

	ll ans = 0;
	for (int i = MAXN - 1; i; i--){
		for (int w = 1; w <= C; w++){
			f[w][i] = f[w - 1][i];

			int rem = i/pp[w-1]%10;
			if (rem < 9)
				f[w][i] = ((f[w][i] + f[w][i + pp[w-1]])%MOD + e[cur][i+pp[w-1]]) % MOD;
		}
		e[cur][i] -= f[C][i];
		while (e[cur][i] < 0) e[cur][i] += MOD;
		ans ^= 1ll*i*e[cur][i];
	}
	printf("%lld\n", ans);
	return 0;
}
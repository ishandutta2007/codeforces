#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e6 + 1000;
const int MOD = 1e9 + 7;

int mx[MAXN], zz[MAXN];
bool pr[MAXN];
ll ss[MAXN], tt[MAXN];
int sec[20], sz, sv[20];

ll pw(ll a, int b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

ll choose(ll a, ll b){return ss[a] * tt[b] % MOD * tt[a - b] % MOD;}

int main(){
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)	ss[i] = ss[i - 1] * i % MOD;
	tt[0] = tt[1] = 1;
	tt[MAXN - 1] = pw(ss[MAXN - 1], MOD - 2);
	for (int i = MAXN-2; i>1; i--)
		tt[i] = tt[i+1] * (i+1) % MOD;

	for (int i = 2; i < MAXN; i++)
		if (!pr[i])
			for (int j = i; j < MAXN; j += i)
				mx[j] = i, pr[j] = 1;
	for (int i = 2; i < MAXN; i++)
		zz[i] = i/mx[i];

	int q;	scanf("%d", &q);
	while (q--){
		int r, x;	scanf("%d %d", &r, &x);
		int lst = -1, temp = x;
		sz = 0;
		while (temp^1){
			if (lst == mx[temp])
				++sec[sz - 1];
			else
				sec[sz++] = 1;
			lst = mx[temp];
			temp = zz[temp];
		}

		sv[0] = 1;
		for (int i = 0; i + 1 < sz; i++)
			sv[i + 1] = choose(sec[i]+r, r) * sv[i] % MOD;
		int ans = 0;
		for (int i = sz-1; ~i; i--){
			ans = (ans + choose(sec[i]-1+r, r)*sv[i]%MOD*temp) % MOD;
			temp = (choose(sec[i]+r, r) + choose(sec[i]-1+r, r)) % MOD * temp % MOD;
		}
		temp = 1;
		for (int i = 0; i < sz; i++)
			temp = choose(sec[i]+r, r) * temp % MOD;
		ans = (ans + temp) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}
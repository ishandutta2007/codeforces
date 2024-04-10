#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
const int MN = 2e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int fac[MN], invfac[MN], dp1[MN], dp[MN][25];
int inv (int base) {
	int exp = MOD-2, res = 1;
	while (exp) {
		if (exp&1) res = res * 1LL * base % MOD;
		base = base * 1LL * base % MOD;
		exp>>=1;
	}
	return res;
}
int choose (int n, int k) {
	return fac[n] * 1LL * invfac[n-k]%MOD * 1LL * invfac[k] % MOD;
}
int main() {
	int n,m,k,s;
	scanf ("%d %d %d %d",&n,&m,&k,&s);
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= n+m; i++) fac[i] = i * 1LL * fac[i-1] % MOD;
	invfac[n+m] = inv(fac[n+m]);
	for (int i = n+m-1; i >= 1; i--) invfac[i] = invfac[i+1] * 1LL * (i+1) % MOD;
	vector<pii> blocc(k+2);
	for (int i = 1; i <= k; i++) scanf ("%d %d",&blocc[i].first,&blocc[i].second);
	blocc[++k] = {n,m};
	sort(1+all(blocc));
	int cango = -1, cur = s;
	while (cur != 1) {
		cango++;
		cur = (cur+1)/2;
	} 
	for (int i = 1; i <= k; i++) {
		dp1[i] = choose(blocc[i].first+blocc[i].second-2,blocc[i].first-1);
		for (int j = i-1; j >= 1; j--) if (blocc[j].first <= blocc[i].first && blocc[j].second <= blocc[i].second) {
			dp1[i] -= dp1[j] * 1LL * choose(blocc[i].first-blocc[j].first+blocc[i].second-blocc[j].second,blocc[i].first-blocc[j].first)%MOD;
			if (dp1[i] < 0) dp1[i] += MOD;
		}
	}
	for (int i = k-1; i >= 1; i--) {
		for (int thru = 0; thru <= cango; thru++) {
			dp[i][thru] = choose(n-blocc[i].x+m-blocc[i].y,n-blocc[i].x);
			for (int j = thru-1; j >= 0; j--) {
				dp[i][thru] -= dp[i][j];
				if (dp[i][thru] < 0) dp[i][thru] += MOD;
			}
			for (int j = i+1; j < k; j++) if (blocc[j].x >= blocc[i].x && blocc[j].y >= blocc[i].y){
				dp[i][thru] -= choose(blocc[j].x-blocc[i].x+blocc[j].y-blocc[i].y,blocc[j].x-blocc[i].x) * 1LL * dp[j][thru] % MOD;
				if (dp[i][thru] < 0) dp[i][thru] += MOD;
			}
		}
	}
	int tot = choose(n+m-2,n-1), invtot = inv(tot), sofar = 0, ret = 0; cur = s;
	for (int take = 0; cur != 1; take++, cur = (cur + 1) / 2) {
		int go = 0;
		if (take == 0) go = dp1[k];
		else {
			for (int f = 1; f < k; f++) {
				go += dp1[f] * 1LL * dp[f][take-1] % MOD;
				if (go >= MOD) go -= MOD;
			}
		}
		sofar += go;
		if (sofar >= MOD) sofar -= MOD;
		ret += go * 1LL * invtot % MOD * cur % MOD;
		if (ret >= MOD) ret -= MOD; 
	}
	tot -= sofar;
	if (tot < 0) tot += MOD;
	ret += tot * 1LL * invtot % MOD;
	if (ret>=MOD) ret -= MOD;
	printf ("%d\n",ret);
    return 0;
}
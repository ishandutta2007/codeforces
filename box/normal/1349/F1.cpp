// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 998244353;

int _dp[100005], *dp, ans[100005];
int fac[100005], inv[100005], ifa[100005];
__attribute__((always_inline)) inline void redc(int& x) { x += (x >> 31) & MOD; }

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	dp = &_dp[1];
	int n; cin >> n;
	fac[0] = fac[1] = inv[0] = inv[1] = ifa[0] = ifa[1] = 1;
	iter(i, 2, n+1) {
		fac[i] = 1ll * fac[i-1] * i % MOD;
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		ifa[i] = 1ll * ifa[i-1] * inv[i] % MOD;
	}
	dp[0] = 1;
	rep1(j, n) {
		if(j != 1) {
			int th=j/2;
			for(int i=th; i>=0; i--) dp[i] = (1ll*(i+1)*dp[i]+1ll*(j-i)*dp[i-1]) % MOD;
			if(!(j%2)) dp[th]=dp[th-1];
		}
		int q = ifa[j];
		for(int i=j/2-1; i>=0; i--) {
			int t = (1ll*dp[i]*q)%MOD-MOD;
			redc(ans[i] += t);
			redc(ans[j-1-i] += t);
		}
		if(j%2) ans[j/2] = (ans[j/2] + 1ll*dp[j/2]*q)%MOD;
	}
	rep(i, n) cout << (1ll*ans[i]*fac[n])%MOD << " \n"[i==n-1];
}
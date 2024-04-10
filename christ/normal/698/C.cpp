#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
double dp[1 << 20];
int main () { 
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<double> w(n);
	for (auto &au : w) scanf ("%lf",&au);
	for (int wot = 0; wot < n; wot++) {
		dp[0] = w[wot]; double ans = dp[0];
		for (int mask = 1; mask < (1 << n); mask++) if ((mask>>wot&1^1) && __builtin_popcount(mask) < k) {
			double s1=0,s2=0;
			for (int i = 0; i < n; i++) if (mask>>i&1) s1 += dp[mask ^ (1 << i)] * w[i], s2 += w[i];
			dp[mask] = abs(s2 - 1) <= 1e-8 ? s1 : s1 / (1 - s2);
			ans += dp[mask];
		}
		printf ("%.8f ",ans);
	}
	printf ("\n");
    return 0;
}
//f(step,mask > 0)
// = sum(f(step-1,mask ^ (1 << i)) + f(step-1,mask)) * w[i] for i in mask
//f(step,mask) = f(step-1,mask) = x
//x = sum(f(step-1,mask ^ (1 << i)) + x) * w[i] for i in mask
//f(mask) = sum(f(mask ^ (1 << i)) + f(mask)) * w[i] for i in mask
//f(mask) = sum(f(mask ^ (1 << i))*w[i]) + sum((f(mask) * w[i]) for i in mask
//f(mask) = sum(f(mask ^ (1 << i))*w[i]) + f(mask)*sum(w[i]) for i in mask
//f(mask)(1 - sum(w[i]) for i in mask) = sum(f(mask ^ (1 << i))*w[i])
//f(mask) = sum((f(mask ^ (1 << i))) * w[i]) / (1 - sum(w[i]))
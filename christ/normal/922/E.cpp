#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e5+3, MOD = 1e9+7;
const double EPS = 1e-15;
ll dp[10005];
int main() {
	int n,w,b,x;
	scanf ("%d %d %d %d",&n,&w,&b,&x);
	vector<int> c(n+1), cost(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&c[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&cost[i]);
	memset(dp,-0x3f,sizeof dp);
	dp[0] = w; int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += c[i];
		for (int have = sum; have >= 1; have--) {
			for (int take = min(have,c[i]); take >= 1; take--) if (dp[have-take]-(ll)cost[i]*take >= 0){
				dp[have] = max(dp[have],dp[have-take]-(ll)cost[i]*take);
			}
			dp[have] = min(dp[have]+x,w+(ll)have*b);
		}
	} 
	int ret = 0;
	for (int i = 1; i <= sum; i++) if (dp[i]>=0) ret = i;
	printf ("%d\n",ret);
    return 0;
}
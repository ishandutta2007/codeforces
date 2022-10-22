#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int n;
	scanf ("%d",&n);
	vector<pii> a(n+1); int ind = 0; vector<ll> dp(n+1); vector<pli> pma(n+1); vector<int> from(n+1,0); vector<int> which(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i].first), a[i].second = i;
	sort(all(a));fill(all(dp),LLONG_MAX>>1);
	dp[0] = 0;
	pma[0] = {0,0}; //dp[i-1] - a[i].first
	for (int i = 1; i <= n; i++) {
		if (i > 2) {
			dp[i] = pma[i-2].first + a[i].first;
			from[i] = pma[i-2].second;
		}
		if (dp[i-1] - a[i].first < pma[i-1].first) {
			pma[i] = {dp[i-1]-a[i].first,i};
		}  else pma[i] = pma[i-1];
	}
	int cur = n, team = 0;
	while (cur) {
		++team;
		for (int i = cur; i >= from[cur]; i--) which[a[i].second] = team;
		cur = from[cur]-1;
	}
	printf ("%lld %d\n",dp[n],team);
	for (int i = 1; i <= n; i++) printf ("%d ",which[i]);
	printf ("\n");
    return 0;
}
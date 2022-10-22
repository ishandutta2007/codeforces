#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	vector<pii> thing;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] != a[i-1]) thing.emplace_back(a[i],1);
		else thing.back().second++;
	}
	sort(all(thing),[](pii a, pii b) {return a.second < b.second;});
	vector<vector<int>> dp(thing.size()); int ret = 0;
	for (int i = thing.size()-1; i >= 0; i--) {
		dp[i].resize(thing[i].second+1);
		for (int take = 1; take <= thing[i].second; take++) {
			dp[i][take] = take;
			if (i+1!=dp.size() && dp[i+1].size() > take*2) dp[i][take] += dp[i+1][take*2];
			ret = max(ret,dp[i][take]);
		}
	}
	printf ("%d\n",ret);
    return 0;
}
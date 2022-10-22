#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n+1), v(n+1);
	vector<vector<int>> uni(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&v[i]);
	for (int i = 1; i <= n; i++) uni[a[i]].push_back(v[i]);
	vector<long long> ans(n+1);
	for (int i = 1; i <= n; i++) if (!uni[i].empty()) {
		sort(uni[i].begin(),uni[i].end());
		vector<long long> psa;
		for (int v : uni[i]) psa.push_back((psa.empty() ? 0 : psa.back()) + v);
		for (int k = 1; k <= (int)uni[i].size(); k++) {
			ans[k] += psa.back();
			int dont = ((int)uni[i].size()) % k;
			if (dont > 0) ans[k] -= psa[dont-1];
		}
	}
	for (int i = 1; i <= n; i++) printf ("%lld%c",ans[i]," \n"[i==n]);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
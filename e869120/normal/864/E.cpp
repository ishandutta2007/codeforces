#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
vector<tuple<int, int, int, int>>v; int n, a[109], b[109], c[109], d[109], dp[109][2009], pre[109][2009];
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i] >> b[i] >> c[i]; v.push_back(make_tuple(b[i], c[i], a[i], i)); }
	sort(v.begin(), v.end());
	for (int i = 0; i < 109; i++) { for (int j = 0; j < 2009; j++)dp[i][j] = -1000000009; }
	dp[0][0] = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j <= 2000; j++) { dp[i + 1][j] = dp[i][j]; pre[i + 1][j] = j; }
		for (int j = get<0>(v[i]) - 1; j >= get<2>(v[i]); j--) {
			int cost = dp[i][j - get<2>(v[i])] + get<1>(v[i]);
			if (dp[i + 1][j] < cost) {
				dp[i + 1][j] = cost;
				pre[i + 1][j] = j - get<2>(v[i]);
			}
		}
	}
	int maxn = 0, maxp = 0, cx = n; for (int i = 0; i <= 2000; i++) { if (maxn < dp[n][i]) { maxn = dp[n][i]; maxp = i; } }
	cout << maxn << endl; vector<int>ret;
	while (cx >= 1) { if (pre[cx][maxp] != maxp) { ret.push_back(get<3>(v[cx - 1]) + 1); maxp = pre[cx][maxp]; }cx--; }
	reverse(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) { if (i)cout << " "; cout << ret[i]; }cout << endl;
	return 0;
}
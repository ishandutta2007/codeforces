#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n, a[100005], p1, p2, dp1[100005], dp2[100005];
vector<pair<long long, long long>>x[100005];
bool used1[100005], used2[100005], used3[100005], y[100005];


void dfs1(int pos, long long rec) {
	if (used1[pos] == true)return;

	dp1[pos] = rec; used1[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) { dfs1(x[pos][i].first, rec + x[pos][i].second); }
}
void dfs2(int pos) {
	if (used2[pos] == true)return;
	used2[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used2[x[pos][i].first] == true)continue;
		dp2[x[pos][i].first] = min(dp2[pos], dp1[x[pos][i].first]);
		dfs2(x[pos][i].first);
	}
}
void dfs3(int pos, bool rec) {
	if (used3[pos] == true)return;
	used3[pos] = true; y[pos] = rec;
	for (int i = 0; i < x[pos].size(); i++) {
		dfs3(x[pos][i].first, max(rec, y[x[pos][i].first]));
	}
}

int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 2; i <= n; i++) { cin >> p1 >> p2; x[i].push_back(make_pair(p1, p2)); x[p1].push_back(make_pair(i, p2)); }
	dfs1(1, 0); dp2[1] = min(dp2[1], dp1[1]); dfs2(1);

	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < (dp1[i] - dp2[i])) { y[i] = true; }
	}
	dfs3(1, y[1]);
	for (int i = 1; i <= n; i++) { if (y[i] == true)cnt++; }
	cout << cnt << endl;
	return 0;
}
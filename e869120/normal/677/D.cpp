#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int H, W, p, a[308][308], dp[308][308]; vector<pair<int, int>>V[90008]; bool used[308][308];
void dfs(int F) {
	for (int i = 0; i < V[F - 1].size(); i++)used[V[F - 1][i].first][V[F - 1][i].second] = true;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { if (used[i][j] == false)dp[i][j] = (1 << 30); }
	}
	for (int i = 0; i < V[F - 1].size(); i++)used[V[F - 1][i].first][V[F - 1][i].second] = false;
	queue<tuple<int, int, int>>Q;
	vector<tuple<int, int, int>>VV;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { if (dp[i][j] < (1 << 30))VV.push_back(make_tuple(dp[i][j], i, j)); }
	}
	sort(VV.begin(), VV.end()); int vx = 0;
	if (VV.size() == 0) { cout << "! " << F << endl; return; }
	Q.push(VV[0]);
	while (!Q.empty()) {
		int co = get<0>(Q.front()), cx = get<1>(Q.front()), cy = get<2>(Q.front()); Q.pop();
		while (vx < VV.size() && get<0>(VV[vx]) <= co) { Q.push(VV[vx]); vx++; }
		int fx[4] = { 0,1,0,-1 }, fy[4] = { 1,0,-1,0 };
		for (int i = 0; i < 4; i++) {
			int gx = cx + fx[i], gy = cy + fy[i];
			if (gx <= 0 || gy <= 0 || gx > H || gy > W)continue;
			if (dp[gx][gy] > dp[cx][cy] + 1) {
				dp[gx][gy] = dp[cx][cy] + 1;
				Q.push(make_tuple(dp[gx][gy], gx, gy));
			}
		}
		if (Q.empty() && vx < VV.size()) { Q.push(VV[vx]); }
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { if (dp[i][j] == (1 << 30))cout << "? " << F << " " << i << " " << j << endl; }
	}
	for (int i = 0; i < V[F].size(); i++)used[V[F][i].first][V[F][i].second] = true;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { if (used[i][j] == false)dp[i][j] = (1 << 30); }
	}
	for (int i = 0; i < V[F].size(); i++)used[V[F][i].first][V[F][i].second] = false;
}
int main() {
	cin >> H >> W >> p;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> a[i][j]; V[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++)dp[i][j] = (1 << 30); }
	dp[1][1] = 0; V[0].push_back(make_pair(1, 1));
	for (int i = 1; i <= p; i++) {
		if (1LL * (long long)V[i - 1].size()*(long long)V[i].size() <= 200000LL) {
			for (int j = 0; j < V[i].size(); j++) {
				int minx = (1 << 30);
				for (int k = 0; k < V[i - 1].size(); k++) {
					int dst = abs(V[i - 1][k].first - V[i][j].first) + abs(V[i - 1][k].second - V[i][j].second);
					minx = min(minx, dst + dp[V[i - 1][k].first][V[i - 1][k].second]);
				}
				dp[V[i][j].first][V[i][j].second] = minx;
			}
			for (int j = 0; j < V[i - 1].size(); j++) {
				if (i == 1 && V[i - 1][j] == make_pair(1, 1))continue;
				dp[V[i - 1][j].first][V[i - 1][j].second] = (1 << 30);
			}
		}
		else {
			dfs(i);
		}
	}
	cout << dp[V[p][0].first][V[p][0].second] << endl;
	return 0;
}
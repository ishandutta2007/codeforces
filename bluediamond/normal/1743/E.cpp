#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#define int long long
int p[3], w[3];
int inith, s;

void minup(int& a, int b) {
	a = min(a, b);
}

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	cin >> p[1] >> w[1];
	cin >> p[2] >> w[2];
	cin >> inith >> s;

	vector<pair<int, int>> order;
	for (int t = 1; t <= 3 * inith; t++) {
		order.push_back({ t * w[1], 1 });
	}
	for (int t = 1; t <= 3 * inith; t++) {
		order.push_back({ t * w[2], 2 });
	}
	sort(order.begin(), order.end());

	vector<vector<int>> nxtc(3, vector<int>((int)order.size(), -1));
	for (int x = 1; x <= 2; x++) {
		for (int i = (int)order.size() - 1; i >= 0; i--) {
			if (i + 1 < (int)order.size()) {
				nxtc[x][i] = nxtc[x][i + 1];
			}
			if (order[i].second == x) {
				nxtc[x][i] = i;
			}
		}
	}

	const int INF = (int)1e18 + 7;
	vector<vector<int>> dp(inith + 1, vector<int>(2 * inith, INF));
	int sol = INF;
	dp[inith][0] = 0;

	for (int h = inith; h >= 0; h--) {
		for (int i = 0; i < 2 * inith; i++) {
			if (dp[h][i] == INF) {
				continue;
			}
			//	cout<<" = "<<h<<", "<<i<<" : "<<dp[h][i]<<"\n";

			if (h == 0) {
				continue;
			}
			assert(i + 1 < 2 * inith);
			int nxt = order[i].second;
			assert(nxt == 1 || nxt == 2);
			int oth = 3 - nxt;
			int j = nxtc[oth][i];
			assert(j > i && j != -1);
			{
				// don't wait
				int nxth = max(0LL, h - (p[nxt] - s));
				minup(dp[nxth][i + 1], dp[h][i]);
				if (nxth == 0) {
					sol = min(sol, dp[h][i] + order[i].first);
				}
			}
			{
				// wait
				int nxth = max(0LL, h - (p[nxt] + p[oth] - s));
				if (nxth == 0) {
					sol = min(sol, dp[h][i] + order[j].first);
				}
				if (nxth == 8) {
					//	cout<< ": " <<order[i].first<<" and "<<order[j].first<<"\n";
				}
				minup(dp[nxth][0], dp[h][i] + order[j].first);
			}
		}
		//	cout<<"--------------------\n";
	}
	cout << sol << "\n";
	return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
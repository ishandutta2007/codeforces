#include <bits/stdc++.h>
using namespace std;

const int N = 202;

vector<pair<int, int> > vec, vec1, ans;
bool dp[N][N][3][3];
pair<int, int> prv[N][N][3][3];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	for (int i = 0; i <= 23; i++) vec.push_back(make_pair(25, i));
	for (int i = 0; i <= 23; i++) vec.push_back(make_pair(i, 25));
	for (int i = 26; i <= 200; i++) vec.push_back(make_pair(i, i - 2)), vec.push_back(make_pair(i - 2, i));
	for (int i = 0; i <= 13; i++) vec1.push_back(make_pair(15, i));
	for (int i = 0; i <= 13; i++) vec1.push_back(make_pair(i, 15));
	for (int i = 16; i <= 200; i++) vec1.push_back(make_pair(i, i - 2)), vec1.push_back(make_pair(i - 2, i));
	dp[0][0][0][0] = 1;
	for (int a = 0; a < N; a++)
		for (int b = 0; b < N; b++) 
			for (int c = 0; c <= 2; c++)
				for (int d = 0; d <= 2; d++) {
					if (!dp[a][b][c][d]) continue;
					for (auto p: vec) {
						int aa = a + p.first, bb = b + p.second;
						int cc = c, dd = d;
						if (p.first  > p.second) cc++;
						else dd++;
						if (max(aa, bb) >= N || max(cc, dd) > 2) continue;
						dp[aa][bb][cc][dd] = 1;
						prv[aa][bb][cc][dd] = p;
					}
				}
				
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int a, b; cin >> a >> b;
		ans.clear();
		int c, d;
		c = 3;
		bool found = 0;
		for (d = 0; d <= 2; d++) {
			vector<pair<int, int> > v = vec;
			if (d == 2) v = vec1;
			for (auto p: v) {
				if (p.first < p.second) continue;
				int aa = a - p.first, bb = b - p.second;
				if (aa < 0 || bb < 0) continue;
				if (dp[aa][bb][c - 1][d]) {
					found = 1;
					printf("%d:%d\n", c, d);
					ans.push_back(p);
					c--;
					while (true) {
						pair<int, int> pp = prv[aa][bb][c][d];
						ans.push_back(pp);
						aa -= pp.first, bb -= pp.second;
						if (pp.first > pp.second) c--;
						else d--;
						if  (c + d == 0) break;
					}
					reverse(ans.begin(), ans.end());
					for (int i = 0; i < ans.size(); i++) printf("%d:%d%c", ans[i].first, ans[i].second, " \n"[i + 1 == ans.size()]);
					break;
				}
			}
			if (found) break;
		}
		if (found) continue;
		d = 3;
		for (c = 2; c >= 0; c--) {
			vector<pair<int, int> > v = vec;
			if (c == 2) v = vec1;
			for (auto p: v) {
				if (p.first > p.second) continue;
				int aa = a - p.first, bb = b - p.second;
				if (aa < 0 || bb < 0) continue;
				if (dp[aa][bb][c][d - 1]) {
					found = 1;
					printf("%d:%d\n", c, d);
					ans.push_back(p);
					d--;
					while (true) {
						pair<int, int> pp = prv[aa][bb][c][d];
						ans.push_back(pp);
						aa -= pp.first, bb -= pp.second;
						if (pp.first > pp.second) c--;
						else d--;
						if  (c + d == 0) break;
					}
					reverse(ans.begin(), ans.end());
					for (int i = 0; i < ans.size(); i++) printf("%d:%d%c", ans[i].first, ans[i].second, " \n"[i + 1 == ans.size()]);
					break;
				}
			}
			if (found) break;
		}
		if (!found) puts("Impossible");
	}			
	return 0;
}
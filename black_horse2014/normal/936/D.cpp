#include <bits/stdc++.h>
using namespace std;

int n, t, m[2];

const int N = 2100000;
const int inf = 1e9 + 7;

int a[2][N], x[N];
int dp[2][N];
bool b[2][N], pr[2][N];

set<int> H[2];

int main() {

	cin >> n >> m[0] >> m[1] >> t;
	int xn = 0;
	x[xn++] = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < m[j]; i++) {
			scanf("%d", &a[j][i]);
			H[j].insert(a[j][i]);
			x[xn++] = a[j][i] + 1;
		}
	}
	if (a[0][0] == 1 && a[1][0] == 1) return puts("No"), 0;
	x[xn++] = n + 1;
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < m[j]; i++) b[j][lower_bound(x, x + xn, a[j][i] + 1) - x] = 1;
	}
	for (int i = 1; i < xn; i++) {
		dp[0][i] = dp[1][i] = inf;
		for (int j = 0; j < 2; j++) if (dp[j][i - 1] != inf) {
			if (b[j][i]) {
				int y = x[i] - 1;
				int cur = (x[i - 1] == y ? dp[j][i - 1] : dp[j][i - 1] + t);
				if (cur < y) {
					if (H[j].count(x[i])) {
//						cerr << j << ' ' << x[i] << endl;
//						cerr << "ok2" << endl;
						if (cur + t <= y) {
//							cerr << "ok1" << endl;
							dp[j][i] = min(dp[j][i], cur + t);
						}
					} else {
						dp[j][i] = min(dp[j][i], cur);
					}
				}
			} else if (H[j].count(x[i])) {
				int y = x[i];
				if (dp[j][i - 1] + t < y) {
					dp[j][i] = min(dp[j][i], dp[j][i - 1] + t);
				}
			} else {
				dp[j][i] = dp[j][i - 1];
			}
		}
		for (int j = 0; j < 2; j++) {
			if (dp[j][i] < inf) {
				if (H[!j].count(x[i])) {
//					cerr << "ok" << endl;
					continue;
				}
				if (dp[!j][i] > max(dp[j][i], x[i] - t)) {
					dp[!j][i] = max(dp[j][i], x[i] - t);
					pr[!j][i] = 1;
				}
			}
		}
//		if (dp[0][i] < inf) cerr << 0 << ' ' << x[i] << endl;
//		if (dp[1][i] < inf) cerr << 1 << ' ' << x[i] << endl;
	}
	if (dp[0][xn - 1] == inf && dp[1][xn - 1] == inf) return puts("No"), 0;
	puts("Yes");
	int state = 0, pos = xn - 1;
	if (dp[1][xn - 1] < inf) state = 1;
	vector<pair<int, int> > ans;
	vector<int> changes;
	while (pos != 0) {
		ans.push_back(make_pair(state, pos));
//		cerr << state << ' ' << x[pos] << endl;
		int flg = pr[state][pos];
		if (flg) {
			changes.push_back(x[pos]);
			state ^= 1;
		} else {
			pos--;
		}
	}
	ans.push_back(make_pair(state, 0));
	if (state == 1) {
		state ^= 1;
		ans.push_back(make_pair(state, 0));
		changes.push_back(0);
	}
	printf("%d\n", changes.size());
	reverse(changes.begin(), changes.end());
	reverse(ans.begin(), ans.end());
	for (int y : changes) printf("%d ", y);
	puts("");
	int last = t;
	vector<pair<int, int> > ret;
	for (pair<int, int> cur : ans) {
		if (cur.first != state) {
			last = max(last, x[cur.second]);
		}
		if (b[cur.first][cur.second]) {
			if (state == cur.first) ret.push_back(make_pair(cur.first + 1, last)), last += t;
		}
		if (H[cur.first].count(x[cur.second])) {
			if (state == cur.first) {
				b[cur.first][cur.second + 1] = 0;
				ret.push_back(make_pair(cur.first + 1, last)), last += t;
			}
		}
		state = cur.first;
	}
	printf("%d\n", ret.size());
	for (pair<int, int> cur : ret) printf("%d %d\n", cur.second, cur.first);
	return 0;
}
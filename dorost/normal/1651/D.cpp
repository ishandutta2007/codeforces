/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 317;
vector <pair <int, int>> a[N], b[N];
vector <int> dp[N], dp2[N];
int l[N], r[N];
int a1[N], a2[N];
map <pair <int, int>, bool> mp;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mp[make_pair(x, y)] = true;
		a[x].push_back(make_pair(y, i));
		b[y].push_back(make_pair(x, i));
		dp[y].push_back(0);
		dp2[y].push_back(0);
	}
	for (int i = 0; i < N; i++) {
		sort(a[i].begin(), a[i].end()); 
		sort(b[i].begin(), b[i].end()); 
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (int)b[i].size(); j++) {
			if (j == 0) 
				dp[i][j] = 1;
			else {
				if (b[i][j].F == b[i][j - 1].F + 1)
					dp[i][j] = dp[i][j - 1] + 1;
				else
					dp[i][j] = 1;
			}
			l[b[i][j].S] = dp[i][j];
		}
		for (int j = (int)b[i].size() - 1; j >= 0; j--) {
			if (j == (int)b[i].size() - 1) 
				dp2[i][j] = 1;
			else {
				if (b[i][j].F == b[i][j + 1].F - 1)
					dp2[i][j] = dp2[i][j + 1] + 1;
				else
					dp2[i][j] = 1;
			}
			r[b[i][j].S] = dp2[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			int x = i, y = a[i][j].F, in = a[i][j].S;
			int an = min(l[in], r[in]);
			if (l[in] < r[in]) {
				a1[in] = x - l[in];
				a2[in] = y;
			} else {
				a1[in] = x + r[in];
				a2[in] = y;
			}
			for (int k = j + 1; k <= j + M; k++) {
				if (k >= (int)a[i].size() || a[i][k].F != a[i][k - 1].F + 1) {
					if (a[i][k - 1].F + 1 - y < an) {
						a1[in] = x;
						a2[in] = a[i][k - 1].F + 1;
						an = a[i][k - 1].F + 1 - y;
					}
					break;
				} else {
					if (a[i][k].F - y + min(l[a[i][k].S], r[a[i][k].S]) < an) {
						an = a[i][k].F - y + min(l[a[i][k].S], r[a[i][k].S]);
						int in2 = a[i][k].S;
						if (l[in2] < r[in2]) {
							a1[in] = x - l[in2];
							a2[in] = a[i][k].F;
						} else {
							a1[in] = x + r[in2];
							a2[in] = a[i][k].F;
						}
					}
				}
			}
			for (int k = j - 1; k >= j - M; k--) {
				if (k < 0 || a[i][k].F != a[i][k + 1].F - 1) {
					if (y - (a[i][k + 1].F - 1) < an) {
						a1[in] = x;
						a2[in] = a[i][k + 1].F - 1;
						an = y - (a[i][k + 1].F - 1);
					}
					break;
				} else {
					if (y - a[i][k].F + min(l[a[i][k].S], r[a[i][k].S]) < an) {
						an = y - a[i][k].F + min(l[a[i][k].S], r[a[i][k].S]);
						int in2 = a[i][k].S;
						if (l[in2] < r[in2]) {
							a1[in] = x - l[in2];
							a2[in] = a[i][k].F;
						} else {
							a1[in] = x + r[in2];
							a2[in] = a[i][k].F;
						}
					}
				}
			}
			assert (an <= M);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a1[i] << ' ' << a2[i] << '\n';
	}
}
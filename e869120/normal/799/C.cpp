#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
int n, a, b, c[100009], d[100009], e[100009], maxn; vector<pair<int, int>>C, D;
int solve(vector<pair<int, int>>E, int f) {
	for (int i = 0; i < 100009; i++)e[i] = 0;
	for (int i = 0; i < E.size(); i++)e[i] = max(e[i], E[i].second);
	for (int i = 1; i < 100009; i++)e[i] = max(e[i], e[i - 1]);
	int res = 0;
	for (int i = 0; i < E.size(); i++) {
		int pos1 = lower_bound(E.begin(), E.end(), make_pair(f - E[i].first, 1 << 30)) - E.begin(); pos1--;
		pos1 = min(pos1, i - 1);
		if (pos1 < 0 || e[pos1] == 0)continue;
		res = max(res, E[i].second + e[pos1]);
	}
	return res;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		int e1, e2; char e3; cin >> e1 >> e2 >> e3;
		if (e3 == 'C')c[e2] = max(c[e2], e1), C.push_back(make_pair(e2, e1));
		if (e3 == 'D')d[e2] = max(d[e2], e1), D.push_back(make_pair(e2, e1));
	}
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	for (int i = 1; i <= 100002; i++)c[i] = max(c[i], c[i - 1]);
	for (int i = 1; i <= 100002; i++)d[i] = max(d[i], d[i - 1]);
	if (c[a] >= 1 && d[b] >= 1)maxn = c[a] + d[b];
	maxn = max(maxn, solve(C, a));
	maxn = max(maxn, solve(D, b));
	cout << maxn << endl;
	return 0;
}
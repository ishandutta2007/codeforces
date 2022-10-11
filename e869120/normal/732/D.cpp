#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int>>x; int a[110000], b[110000], n, m; bool used[110000];
bool solve(int d) {
	if (d >= n)d = n; x.clear();
	for (int i = 1; i <= m; i++)used[i] = false;
	for (int i = d; i >= 1; i--) {
		if (a[i] >= 1 && used[a[i]] == false) {
			used[a[i]] = true; x.push_back(make_pair(i, a[i]));
		}
	}
	for (int i = 1; i <= m; i++) { if (used[i] == false)return false; }
	sort(x.begin(), x.end()); int e = 0;
	for (int i = 0; i < x.size(); i++) {
		e += b[x[i].second] + 1; if (x[i].first < e)return false;
	}
	return true;
}
int main() {
	cin >> n >> m; for (int i = 1; i <= n; i++)cin >> a[i]; for (int i = 1; i <= m; i++)cin >> b[i];
	int L = 0, R = 200000, M;
	while (true) {
		M = (L + R) / 2; bool p1 = solve(M - 1), p2 = solve(M);
		if (M >= 199999) { cout << "-1" << endl; break; }
		if (p1 == false && p2 == true) { cout << M << endl; break; }
		if (p1 == true)R = M;
		if (p2 == false)L = M;
	}
	return 0;
}
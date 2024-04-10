#include<iostream>
#include<vector>
using namespace std;
int n, m, a[3000], b[3000];
vector<pair<int,int> >vec[3000];
void sousa(int p1, int p2) {
	for (int i = 0; i < vec[p1].size(); i++) {
		if (vec[p1][i].second == 0) {
			vec[p1][i].second = 1;
			vec[p2].push_back(make_pair(vec[p1][i].first, 0));
			a[vec[p1][i].first] = p2;
			return;
		}
	}
}
int main() {
	cin >> n >> m; int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; if (a[i] <= m) { b[a[i]]++; vec[a[i]].push_back(make_pair(i, 0)); }
	}
	int T = n / m; int T2 = n%m, T1 = m - T2, T3 = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			while (b[j] <= T - 1 && b[i] > T + 1) {
				sousa(i, j); cnt++;
				b[j]++; b[i]--;
			}
		}
	}
	for (int i = 1; i <= m; i++) { if (b[i] == T + 1)T3++; }
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[j] <= T - 1 && b[i] == T + 1 && T3 > T2) {
				sousa(i, j); cnt++; b[j]++; b[i]--; T3--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > m) {
			for (int j = 1; j <= m; j++) {
				if (b[j] <= T - 1) { a[i] = j; b[j]++; cnt++; break; }
			}
		}
	}
	cout << T << ' ' << cnt << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << a[i]; }cout << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[1000], b[1000], n, m; vector<pair<int, int>>I; vector<pair<int, char>>ret;
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> m; for (int i = 1; i <= m; i++)cin >> b[i];
	int G = 0, H = 1, V = 1;
	for (int i = 1; i <= n; i++) {
		G += a[i];
		if (G > b[H]) { cout << "NO" << endl; return 0; }
		if (G == b[H]) {
			I.push_back(make_pair(V, i)); V = i + 1; H++; G = 0;
			if (H > m && i != n) { cout << "NO" << endl; return 0; }
		}
	}
	if (H <= m) { cout << "NO" << endl; return 0; }
	for (int i = 0; i < I.size(); i++) {
		if (I[i].second - I[i].first == 0)continue;
		int maxn = 0; for (int j = I[i].first; j <= I[i].second; j++) { maxn = max(maxn, a[j]); }
		int cnt1 = 0, cnt2 = -1;
		for (int j = I[i].first; j <= I[i].second; j++) {
			if (maxn == a[j]) {
				cnt1++;
				if ((j != I[i].first && a[j - 1] != a[j]) || (j != I[i].second && a[j] != a[j + 1]))cnt2 = j - I[i].first;
			}
		}
		if (cnt1 == (I[i].second - I[i].first + 1) || cnt2 == -1) { cout << "NO" << endl; return 0; }
		if (cnt2 == 0 || a[cnt2 + I[i].first] != a[cnt2 + I[i].first - 1]) {
			for (int j = 0; j < cnt2; j++) { ret.push_back(make_pair(i + 1 + cnt2 - j, 'L')); }
			for (int j = 0; j < (I[i].second - I[i].first) - cnt2; j++) { ret.push_back(make_pair(i + 1, 'R')); }
		}
		else {
			for (int j = 0; j < (I[i].second - I[i].first) - cnt2; j++) { ret.push_back(make_pair(i + 1 + cnt2, 'R')); }
			for (int j = 0; j < cnt2; j++) { ret.push_back(make_pair(i + 1 + cnt2 - j, 'L')); }
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < ret.size(); i++)cout << ret[i].first << ' ' << ret[i].second << endl;
	return 0;
}
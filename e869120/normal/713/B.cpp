#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
const int max_bit = 17; int n, G, a[10], b[10], c[6][6][6][6], Debug = 0;
int Ask(int p1, int p2, int p3, int p4) {
	cout << "? " << min(n, p1 + 1) << ' ' << min(n, p2 + 1) << ' ' << min(n, p3) << ' ' << min(n, p4) << endl;
	if (Debug == 0) { int F; cin >> F; return F; }
	int F = 0;
	if (b[0] >= min(n, p1 + 1) && min(n, p3) >= b[2] && b[1] >= min(n, p2 + 1) && min(n, p4) >= b[3])F++;
	if (b[4] >= min(n, p1 + 1) && min(n, p3) >= b[6] && b[5] >= min(n, p2 + 1) && min(n, p4) >= b[7])F++;
	cout << F << endl;
	return F;
}
int main() {
	cin >> n;
	if (Debug == 1) { for (int i = 0; i < 8; i++)cin >> b[i]; }
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, 0, n, G + (1 << i)); if (p == 0)G += (1 << i);
	}
	a[3] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, 0, n, G + (1 << i)); if (p <= 1)G += (1 << i);
	}
	a[7] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, 0, G + (1 << i), n); if (p == 0)G += (1 << i);
	}
	a[2] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, 0, G + (1 << i), n); if (p <= 1)G += (1 << i);
	}
	a[6] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, G + (1 << i), n, n); if (p >= 1)G += (1 << i);
	}
	a[5] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(0, G + (1 << i), n, n); if (p >= 2)G += (1 << i);
	}
	a[1] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(G + (1 << i), 0, n, n); if (p >= 1)G += (1 << i);
	}
	a[4] = G;
	G = 0;
	for (int i = max_bit - 1; i >= 0; i--) {
		int p = Ask(G + (1 << i), 0, n, n); if (p >= 2)G += (1 << i);
	}
	a[0] = G;
	vector<int>X = { a[0],a[2],a[4],a[6] };
	vector<int>Y = { a[1],a[3],a[5],a[7] };
	for (int i = 0; i < X.size(); i++)X[i] = min(X[i], n - 1);
	for (int i = 0; i < Y.size(); i++)Y[i] = min(Y[i], n - 1);
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	vector<tuple<int, int, int, int>>ans, res;
	for (int i = 0; i < X.size(); i++) {
		for (int j = i + 1; j < X.size(); j++) {
			for (int k = 0; k < Y.size(); k++) {
				for (int l = k + 1; l < Y.size(); l++) {
					c[i][j][k][l] = Ask(X[i], Y[k], X[j] + 1, Y[l] + 1);
					if (c[i][j][k][l] == 1)ans.push_back(make_tuple(X[i], Y[k], X[j], Y[l]));
				}
			}
		}
	}
	sort(ans.begin(), ans.end()); ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		bool OK = true;
		for (int j = 0; j < ans.size(); j++) {
			if (i == j)continue;
			if (get<0>(ans[i]) <= get<0>(ans[j]) && get<2>(ans[j]) <= get<2>(ans[i]) && get<1>(ans[i]) <= get<1>(ans[j]) && get<3>(ans[j]) <= get<3>(ans[i]))OK = false;
		}
		if (OK == true)res.push_back(ans[i]);
	}
	cout << "! ";
	cout << get<0>(res[0]) + 1 << ' ' << get<1>(res[0]) + 1 << ' ' << get<2>(res[0]) + 1 << ' ' << get<3>(res[0]) + 1 << ' ';
	cout << get<0>(res[1]) + 1 << ' ' << get<1>(res[1]) + 1 << ' ' << get<2>(res[1]) + 1 << ' ' << get<3>(res[1]) + 1 << endl;
	return 0;
}
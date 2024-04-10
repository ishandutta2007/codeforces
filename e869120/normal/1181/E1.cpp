#include <bits/stdc++.h>
using namespace std;

int N, ax[1009], ay[1009], bx[1009], by[1009];

bool solve(int lx, int ly, int rx, int ry, vector<int>vec, bool flag) {
	if (vec.size() == 1) return true;
	vector<int>X, Y;
	for (int i = 0; i < (int)vec.size(); i++) {
		X.push_back(ax[vec[i]]); Y.push_back(ay[vec[i]]);
		X.push_back(bx[vec[i]]); Y.push_back(by[vec[i]]);
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	
	if (flag == false) {
		vector<int> E(X.size() + 2, 0); vector<pair<int, int>> v1; int ml = 2000000000, mr = -1;
		for (int i = 0; i < (int)vec.size(); i++) {
			int pos1 = lower_bound(X.begin(), X.end(), ax[vec[i]]) - X.begin();
			int pos2 = lower_bound(X.begin(), X.end(), bx[vec[i]]) - X.begin();
			E[pos1]++; E[pos2]--; ml = min(ml, ax[vec[i]]); mr = max(mr, bx[vec[i]]);
			v1.push_back(make_pair(ax[vec[i]], vec[i]));
		}
		sort(v1.begin(), v1.end());
		for (int i = 1; i < (int)E.size(); i++) E[i] += E[i - 1];
		
		int pres = -1;
		for (int i = 0; i < (int)E.size(); i++) {
			if (E[i] >= 1) { if (pres == -1) pres = X[i]; }
			else {
				if (pres != -1) {
					if (pres == ml && X[i] == mr) return false;
					vector<int> vec2;
					int pos1 = lower_bound(v1.begin(), v1.end(), make_pair(pres, 0)) - v1.begin();
					int pos2 = lower_bound(v1.begin(), v1.end(), make_pair(X[i], 0)) - v1.begin();
					for (int j = pos1; j < pos2; j++) vec2.push_back(v1[j].second);
					bool K = solve(pres, ly, X[i], ry, vec2, true);
					if (K == false) return false;
					pres = -1;
				}
			}
		}
		return true;
	}
	if (flag == true) {
		vector<int> E(Y.size() + 2, 0); vector<pair<int, int>> v1; int ml = 2000000000, mr = -1;
		for (int i = 0; i < (int)vec.size(); i++) {
			int pos1 = lower_bound(Y.begin(), Y.end(), ay[vec[i]]) - Y.begin();
			int pos2 = lower_bound(Y.begin(), Y.end(), by[vec[i]]) - Y.begin();
			E[pos1]++; E[pos2]--; ml = min(ml, ay[vec[i]]); mr = max(mr, by[vec[i]]);
			v1.push_back(make_pair(ay[vec[i]], vec[i]));
		}
		sort(v1.begin(), v1.end());
		for (int i = 1; i < (int)E.size(); i++) E[i] += E[i - 1];
		
		int pres = -1;
		for (int i = 0; i < (int)E.size(); i++) {
			if (E[i] >= 1) { if (pres == -1) pres = Y[i]; }
			else {
				if (pres != -1) {
					if (pres == ml && Y[i] == mr) return false;
					vector<int> vec2;
					int pos1 = lower_bound(v1.begin(), v1.end(), make_pair(pres, 0)) - v1.begin();
					int pos2 = lower_bound(v1.begin(), v1.end(), make_pair(Y[i], 0)) - v1.begin();
					for (int j = pos1; j < pos2; j++) vec2.push_back(v1[j].second);
					bool K = solve(lx, pres, rx, Y[i], vec2, false);
					if (K == false) return false;
					pres = -1;
				}
			}
		}
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
		ax[i] = ax[i] * 2 + 1;
		ay[i] = ay[i] * 2 + 1;
		bx[i] = bx[i] * 2 - 1;
		by[i] = by[i] * 2 - 1;
	}
	vector<int>V; for (int i = 0; i < N; i++) V.push_back(i);
	bool I1 = solve(0, 0, 2000000000, 2000000000, V, false);
	bool I2 = solve(0, 0, 2000000000, 2000000000, V, true);
	if (I1 == true || I2 == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[100000], b[100000], c[100000], maxr, maxn; pair<int, int>maxid;
map<pair<int, int>, vector<pair<int, int>>>M;
map<pair<int, int>, vector<pair<int, int>>>M3;
map<pair<int, int>, int>used;
int size_(int p1, int p2, int p3) {
	return min(p1, min(p2, p3));
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i]; map<pair<int, int>, int>M2;
		if (M2[make_pair(a[i], b[i])] == 0) { M[make_pair(a[i], b[i])].push_back(make_pair(c[i], i)); M2[make_pair(a[i], b[i])] = 1; }
		if (M2[make_pair(b[i], a[i])] == 0) { M[make_pair(b[i], a[i])].push_back(make_pair(c[i], i)); M2[make_pair(b[i], a[i])] = 1; }
		if (M2[make_pair(a[i], c[i])] == 0) { M[make_pair(a[i], c[i])].push_back(make_pair(b[i], i)); M2[make_pair(a[i], c[i])] = 1; }
		if (M2[make_pair(c[i], a[i])] == 0) { M[make_pair(c[i], a[i])].push_back(make_pair(b[i], i)); M2[make_pair(c[i], a[i])] = 1; }
		if (M2[make_pair(b[i], c[i])] == 0) { M[make_pair(b[i], c[i])].push_back(make_pair(a[i], i)); M2[make_pair(b[i], c[i])] = 1; }
		if (M2[make_pair(c[i], b[i])] == 0) { M[make_pair(c[i], b[i])].push_back(make_pair(a[i], i)); M2[make_pair(c[i], b[i])] = 1; }
		if (maxn < size_(a[i], b[i], c[i])) {
			maxr = 1; maxid = make_pair(i, -1); maxn = size_(a[i], b[i], c[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (i >= 0) {
			if (used[make_pair(a[i], b[i])] == 0) {
				sort(M[make_pair(a[i], b[i])].begin(), M[make_pair(a[i], b[i])].end());
				vector<pair<int, int>>D3 = M[make_pair(a[i], b[i])];
				if (D3.size() >= 1)M3[make_pair(a[i], b[i])].push_back(D3[D3.size() - 1]);
				if (D3.size() >= 2)M3[make_pair(a[i], b[i])].push_back(D3[D3.size() - 2]);
			}
			vector<pair<int, int>>D = M3[make_pair(a[i], b[i])];
			if (D.size() >= 2) {
				int R = D[D.size() - 1].first + D[D.size() - 2].first;
				if (maxn < size_(a[i], b[i], R)) {
					maxn = size_(a[i], b[i], R);
					maxid = make_pair(D[D.size() - 1].second, D[D.size() - 2].second);
					maxr = 2;
				}
			}
			used[make_pair(a[i], b[i])] = 1;
		}
		if (i >= 0) {
			if (used[make_pair(a[i], c[i])] == 0) {
				sort(M[make_pair(a[i], c[i])].begin(), M[make_pair(a[i], c[i])].end());
				vector<pair<int, int>>D3 = M[make_pair(a[i], c[i])];
				if (D3.size() >= 1)M3[make_pair(a[i], c[i])].push_back(D3[D3.size() - 1]);
				if (D3.size() >= 2)M3[make_pair(a[i], c[i])].push_back(D3[D3.size() - 2]);
			}
			vector<pair<int, int>>D = M3[make_pair(a[i], c[i])];
			if (D.size() >= 2) {
				int R = D[D.size() - 1].first + D[D.size() - 2].first;
				if (maxn < size_(a[i], c[i], R)) {
					maxn = size_(a[i], c[i], R);
					maxid = make_pair(D[D.size() - 1].second, D[D.size() - 2].second);
					maxr = 2;
				}
			}
			used[make_pair(a[i], c[i])] = 1;
		}
		if (i >= 0) {
			if (used[make_pair(b[i], c[i])] == 0) {
				sort(M[make_pair(b[i], c[i])].begin(), M[make_pair(b[i], c[i])].end());
				vector<pair<int, int>>D3 = M[make_pair(b[i], c[i])];
				if (D3.size() >= 1)M3[make_pair(b[i], c[i])].push_back(D3[D3.size() - 1]);
				if (D3.size() >= 2)M3[make_pair(b[i], c[i])].push_back(D3[D3.size() - 2]);
			}
			vector<pair<int, int>>D = M3[make_pair(b[i], c[i])];
			if (D.size() >= 2) {
				int R = D[D.size() - 1].first + D[D.size() - 2].first;
				if (maxn < size_(b[i], c[i], R)) {
					maxn = size_(b[i], c[i], R);
					maxid = make_pair(D[D.size() - 1].second, D[D.size() - 2].second);
					maxr = 2;
				}
			}
			used[make_pair(b[i], c[i])] = 1;
		}
	}
	cout << maxr << endl;
	if (maxr == 1)cout << maxid.first + 1 << endl;
	if (maxr == 2)cout << maxid.first + 1 << ' ' << maxid.second + 1 << endl;
	return 0;
}
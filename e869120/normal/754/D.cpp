#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<tuple>
using namespace std;
int n, k, a[400000], b[400000]; vector<tuple<int, int, int>>c;
priority_queue<int, vector<int>, greater<int>>Q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q2;
int main() {
	cin >> n >> k; for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; c.push_back(make_tuple(a[i], 0, i)); c.push_back(make_tuple(b[i], 1, i)); }
	sort(c.begin(), c.end());
	int maxn = 0, maxid1 = (1 << 30), maxid2 = (1 << 30);
	for (int i = 0; i < c.size(); i++) {
		if (get<1>(c[i]) == 0) { Q.push(b[get<2>(c[i])]); }
		while (Q.size() > k)Q.pop();
		if (Q.size() == k) {
			int U = Q.top(), V = U - get<0>(c[i]) + 1;
			if (V > maxn) { maxn = V; maxid1 = get<0>(c[i]); maxid2 = U; }
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] <= maxid1 && maxid2 <= b[i])Q2.push(make_pair(b[i], i));
	}
	while (Q2.size() > k)Q2.pop();
	vector<int>C; while (!Q2.empty()) { C.push_back(Q2.top().second); Q2.pop(); }
	sort(C.begin(), C.end());

	if (C.size() == 0) { for (int i = 0; i < k; i++)C.push_back(i); }
	cout << maxn << endl;
	for (int i = 0; i < C.size(); i++) { if (i)cout << ' '; cout << C[i] + 1; }cout << endl;
	return 0;
}
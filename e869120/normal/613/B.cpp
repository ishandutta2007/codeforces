#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long a[100009], n, A, p, q, m, b1[100009], b2[100009], c[100009], maxn, maxid, maxid2; vector<pair<long long, int>>P;
int main() {
	cin >> n >> A >> p >> q >> m;
	for (int i = 1; i <= n; i++)cin >> a[i]; a[n + 1] = A;
	for (int i = 1; i <= n; i++)P.push_back(make_pair(a[i], i));
	sort(a + 1, a + n + 1); P.push_back(make_pair(0, -1)); sort(P.begin(), P.end());
	for (int i = 1; i <= n + 1; i++)b1[i] = b1[i - 1] + (a[i] - a[i - 1])*(i - 1);
	for (int i = n; i >= 1; i--)b2[i] = b2[i + 1] + (A - a[i]);

	for (int i = 0; i <= n; i++) {
		long long U = m - b2[n + 1 - i];
		if (U < 0)continue;
		long long pos1 = upper_bound(b1, b1 + n + 1, U) - b1; pos1--; pos1 = min(pos1, n - i);
		long long R = A; if (pos1 >= 1) { R = min(A, a[pos1] + (U - b1[pos1]) / pos1); }

		long long S = 1LL * i*p + R*q;
		if (maxn < S) { maxn = S; maxid = i; maxid2 = R; }
	}
	for (int i = 1; i <= n - maxid; i++) { a[i] = max(a[i], maxid2); }
	for (int i = n - maxid + 1; i <= n; i++) { a[i] = A; }
	for (int i = 1; i <= n; i++) { c[P[i].second] = a[i]; }
	cout << maxn << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << c[i]; }cout << endl;
	return 0;
}
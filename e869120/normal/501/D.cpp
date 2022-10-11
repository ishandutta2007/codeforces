#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bit[280000], a[2][280000], n, c[280000];
void add(int p, int x) {
	p++;
	while (p < 280000) { bit[p] += x; p += (p&-p); }
}
int sum(int p) {
	int s = 0; p++;
	while (p >= 1) { s += bit[p]; p -= (p&-p); }
	return s;
}
vector<int>solve(int u) {
	for (int i = 0; i < 280000; i++)bit[i] = 0;
	for (int i = 0; i < 280000; i++)add(i, 1);
	vector<int>Z;
	for (int i = 0; i < n; i++) {
		add(a[u][i], -1); Z.push_back(sum(a[u][i]));
	}
	return Z;
}
int main() {
	cin >> n;
	for (int i = 0; i < 2; i++) { for (int j = 0; j < n; j++)cin >> a[i][j]; }
	for (int i = 0; i < 2; i++) { vector<int>C = solve(i); for (int j = 0; j < C.size(); j++)c[j] += C[j]; }
	for (int i = n - 1; i >= 0; i--) { c[i - 1] += c[i] / (n - i); c[i] %= (n - i); }
	for (int i = 0; i < 280000; i++)bit[i] = 0;
	for (int i = 0; i < 280000; i++)add(i, 1);
	for (int i = 0; i < n; i++) {
		int L = -1, R = 280000, M, maxn = -1;
		for (int j = 0; j < 30; j++) {
			M = (L + R) / 2;
			if (sum(M) <= c[i]) { maxn = max(maxn, M); L = M; }
			else { R = M; }
		}
		if (i)cout << " "; cout << maxn + 1; add(maxn + 1, -1);
	}
	cout << endl;
	return 0;
}
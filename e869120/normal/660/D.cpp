#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, x[100009], y[100009]; map<pair<int, int>, int>M; vector<pair<int, int>>X;
pair<int, int> compress(int p, int q) {
	if (p < 0) { p *= -1; q *= -1; }
	if (p == 0 && q < 0) { q *= -1; }
	return make_pair(p, q);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<int, int> F = compress(x[j] - x[i], y[j] - y[i]);
			X.push_back(F); M[F]++;
		}
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	long long ret = 0;
	for (int i = 0; i < X.size(); i++)ret += 1LL * M[X[i]] * (M[X[i]] - 1) / 2LL;
	cout << ret / 2 << endl;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m, s, t, a[300000], b[300000], c[300000], minx = 1LL << 62;
vector<int>r1, r2;
long long query(long long h) {
	long long J = 0;
	for (int i = 0; i < r1.size(); i++) {
		if (r1[i] > h)return 1LL << 62;
		if (r1[i] * 2 > h)J += r1[i] * 2 - h;
	}
	return J + s;
}
int main() {
	cin >> n >> m >> s >> t; for (int i = 0; i < n; i++)scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= m; i++)cin >> c[i]; c[m + 1] = s; sort(c, c + m + 2);
	for (int i = 0; i <= m; i++)r1.push_back(c[i + 1] - c[i]); sort(r1.begin(), r1.end());
	long long L = 0, R = 1LL << 60, M;
	for (int i = 0; i < 100; i++) {
		M = (L + R) / 2;
		long long T1 = query(M - 1), T2 = query(M);
		if (T1 > t && T2 <= t)break;
		if (T1 <= t)R = M;
		if (T2 > t)L = M;
	}
	for (int i = 0; i < n; i++) {
		if (b[i] >= M)minx = min(minx, a[i]);
	}
	if (minx >= 1LL << 60)minx = -1;
	cout << minx << endl;
	return 0;
}
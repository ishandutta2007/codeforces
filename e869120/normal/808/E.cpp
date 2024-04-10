#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
long long n, m, w[100000], c[100000], maxn, s; vector<long long>R[4];
vector<long long>solve(vector<long long>a, vector<long long>b, long long lim) {
	while (a.size() < lim)a.push_back(0);
	while (b.size() < lim)b.push_back(0);
	vector<long long>p(lim + 1), q(lim + 1);
	p[0] = 0; for (int i = 0; i < lim; i++)p[i + 1] = p[i] + a[i];
	q[0] = 0; for (int i = 0; i < lim; i++)q[i + 1] = q[i] + b[i];
	vector<long long>U;
	for (int i = 0; i < lim; i++) {
		long long L = 0, R = i / 2 + 1, M;
		while (true) {
			M = (L + R) / 2;
			bool p1 = false;
			if ((i - M * 2) >= 2 && (b[i - M * 2 - 1] + b[i - M * 2 - 2]) < a[M])p1 = true;
			bool p2 = false;
			if (M >= 1 && (b[i - M * 2] + b[i - M * 2 + 1]) > a[M - 1])p2 = true;
			if (p1 == false && p2 == false) {
				U.push_back(p[M] + q[i - M * 2]); break;
			}
			if (p1 == true)L = M; else R = M;
		}
	}
	return U;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> c[i];
		R[w[i]].push_back(c[i]);
	}
	for (int i = 1; i <= 3; i++)sort(R[i].begin(), R[i].end(), greater<long long>());
	vector<long long>T = solve(R[2], R[1], 500000);
	for (int i = 0; i <= m / 3; i++) { maxn = max(maxn, s + T[m - i * 3]); if (i < R[3].size())s += R[3][i]; }
	cout << maxn << endl;
	return 0;
}
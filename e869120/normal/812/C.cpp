#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m, a[100000];
long long solve(long long p) {
	if (p > n)return (1LL << 60);
	vector<long long>A;
	for (int i = 0; i < n; i++)A.push_back(a[i] + (i + 1)*p);
	sort(A.begin(), A.end());
	long long ret = 0; for (int i = 0; i < p; i++)ret += A[i];
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	int L = 0, R = n + 1, M;
	while (true) {
		M = (L + R) / 2;
		long long p1 = solve(M), p2 = solve(M + 1);
		if (p1 <= m && p2 > m) { cout << M << ' ' << p1 << endl; break; }
		if (p1 > m)R = M; else L = M;
	}
	return 0;
}
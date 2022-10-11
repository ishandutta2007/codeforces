#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
long long n, a[100005];
long long maximum_profit(vector<long long>x) {
	long long c = 0, d = 0, maxn = 0;
	for (int i = 0; i < x.size(); i++) {
		c += x[i]; d = min(d, c);
		maxn = max(maxn, c - d);
	}
	return maxn;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); }
	vector<long long>E1, E2;
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0) { E1.push_back(abs(a[i + 1] - a[i])); E2.push_back(-abs(a[i + 1] - a[i])); }
		if (i % 2 == 1) { E2.push_back(abs(a[i + 1] - a[i])); E1.push_back(-abs(a[i + 1] - a[i])); }
	}
	cout << max(maximum_profit(E1), maximum_profit(E2)) << endl;
	return 0;
}
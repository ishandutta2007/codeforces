/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200001, K = 10000, M = 5000001;
int a[N], x[M];
pair <int, int> b[M][4];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < min(K, n); i++) {
		for (int j = 0; j < i; j++) {
			int s = a[i] + a[j];
			if (x[s] == 4)
				continue;
			b[s][x[s]] = {j, i};
			x[s]++;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < x[i]; j++) {
			for (int k = 0; k < j; k++) {
				pair <int, int> p = b[i][j], r = b[i][k];
				if (p.S != r.S && p.S != r.F && p.F != r.F && p.F != r.S) {
					cout << "YES\n";
					cout << p.F + 1 << ' ' << p.S + 1 << ' ' << r.F + 1 << ' ' << r.S + 1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
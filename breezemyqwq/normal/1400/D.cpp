#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int a[N];
int k[N][N], g[N][N];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		long long sum = 0;
		cin >> n;
		memset(k, 0, sizeof k);
		memset(g, 0, sizeof g);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) k[i][j] = k[i][j - 1] + (a[i] == a[j]);
			for(int j = n; j; j--) g[i][j] = g[i][j + 1] + (a[i] == a[j]);
		}
		for(int i = 3; i < n; i++) {
			for(int j = 2; j < i; j++) {
				sum += k[i][j - 1] * g[j][i + 1];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
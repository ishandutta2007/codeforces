#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n), b(n);
    for (int i = 0; i < n; i++) {
		a[i].resize(m);
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
		b[i].resize(m);
        for (int j = 0; j < m; j++) cin >> b[i][j];
    }
    for (int i = 0; i < n; i++) {
		int s = 0;
        for (int j = 0; j < m; j++) s ^= a[i][j] ^ b[i][j];
        if (s) return puts("No"), 0;
    }
    for (int i = 0; i < m; i++) {
		int s = 0;
        for (int j = 0; j < n; j++) s ^= a[j][i] ^ b[j][i];
        if (s) return puts("No"), 0;
    }
    puts("Yes");
    return 0;
}
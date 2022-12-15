#include<bits/stdc++.h>
using namespace std;
typedef double db;

bool vis[1005][1005];
db f_[1005][1005];

db f(int n, int m) {
    if (vis[n][m]) return f_[n][m];
    db X = 1.0 / (m + 1);
	if (!n) return X;
	if (!m) return 1;
    vis[n][m] = 1;
    db A = X * m * (1 - f(m - 1, n)), B = X + A;
	db C = 1, D = 1.0 - f(m, n - 1);
	db P = (D - C) / (A - C - B + D);
	return f_[n][m] = P * A + (1 - P) * C;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    db ans = f(n, m);
    printf("%.10lf %.10lf\n", ans, 1 - ans);
}
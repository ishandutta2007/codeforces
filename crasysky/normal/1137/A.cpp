#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1003;
int a[maxn][maxn], c[maxn][maxn], r[maxn][maxn], cc[maxn], rc[maxn], b[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f; 
} 
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			a[i][j] = read();
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j)
			b[j] = a[i][j];
		sort(b + 1, b + 1 + m);
		int k = unique(b + 1, b + 1 + m) - b - 1;
		for (int j = 1; j <= m; ++ j)
			r[i][j] = lower_bound(b + 1, b + 1 + k, a[i][j]) - b;
		rc[i] = k;
	}
	for (int j = 1; j <= m; ++ j){
		for (int i = 1; i <= n; ++ i)
			b[i] = a[i][j];
		sort(b + 1, b + 1 + n);
		int k = unique(b + 1, b + 1 + n) - b - 1;
		for (int i = 1; i <= n; ++ i)
			c[i][j] = lower_bound(b + 1, b + 1 + k, a[i][j]) - b;
		cc[j] = k;
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j)
			cout << max(r[i][j], c[i][j]) + max(rc[i] - r[i][j], cc[j] - c[i][j]) << " ";
		cout << endl;
	}
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 1e9 + 9;
const int maxn = 1e6 + 6;
vector <int> a[maxn];
int ans[maxn][2];
set < Pr > s;
long long read(){
	long long c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j <= m; ++ j)
			a[i].push_back(INF);
	int c = 0;
	for (int x1 = 1, x2 = n; x1 < x2; ++ x1, -- x2)
		for (int i = 1; i <= m; ++ i)
			a[x1][i] = ++ c, a[x2][m - i + 1] = ++ c;
	if (n & 1){
		for (int i = 1; i <= m / 2; ++ i)
			a[(n + 1) / 2][i] = ++ c, a[(n + 1) / 2][m - i + 1] = ++ c;
		if (m & 1)
			a[(n + 1) / 2][(m + 1) / 2] = ++ c;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			ans[a[i][j]][0] = i, ans[a[i][j]][1] = j;
	for (int i = 1; i <= n * m; ++ i)
		printf("%d %d\n", ans[i][0], ans[i][1]);
}
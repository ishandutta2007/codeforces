#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define fi first
#define se second
using namespace std;
const int maxn = 2003;
const int maxs = 2000006;
string s;
pair <int, int> b[maxn];
int _a[maxn][maxn], a[maxn][maxn], tmp[maxn];
int mx[maxs], f[maxs];
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++ cas){
		int n = read(), m = read();
		for (int j = 1; j <= m; ++ j)
			b[j].fi = 0, b[j].se = j;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j){
				_a[i][j] = read();
				b[j].fi = max(b[j].fi, _a[i][j]);
			}
		sort(b + 1, b + 1 + m);
		if (m > n){
			for (int i = 1; i <= n; ++ i)
				for (int j = m; j >= m - n + 1; -- j)
					a[i][m - j + 1] = _a[i][b[j].se];
			m = n;
		}
		else
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j)
					a[i][j] = _a[i][j];
		for (int s = 1; s < 1 << n; ++ s)
			f[s] = 0;
		for (int j = 1; j <= m; ++ j){
			for (int s = 1; s < 1 << n; ++ s)
				mx[s] = 0;
			for (int i = 1; i <= n; ++ i){
				int t = 0;
				for (int k = i; k <= n; ++ k)
					tmp[++ t] = a[k][j];
				for (int k = 1; k < i; ++ k)
					tmp[++ t] = a[k][j];
				for (int s = 1; s < 1 << n; ++ s){
					int sum = 0;
					for (int i = 1; i <= n; ++ i)
						if (s & (1 << i - 1))
							sum += tmp[i];
					mx[s] = max(mx[s], sum);
				}
			}
			for (int s = (1 << n) - 1; s >= 0; -- s)
				for (int _s = s; _s; _s = (_s - 1) & s)
					f[s] = max(f[s], f[s - _s] + mx[_s]);
		}
		cout << f[(1 << n) - 1] << endl;
	}
}
/*
3
2 3
2 5 7
4 2 4
3 6
4 1 5 2 10 4
8 6 6 4 9 10
5 4 9 5 8 7
3 3
9 9 9
1 1 1
1 1 1
*/
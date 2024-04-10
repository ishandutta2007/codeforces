#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 52;
const int P = 998244353;
int a[maxn], w[maxn], f[maxn][maxn][maxn];
int fpw(int x, int y){
	int ans = 1;
	for (; y; y >>= 1, x = 1LL * x * x % P)
		if (y & 1)
			ans = 1LL * ans * x % P;
	return ans;
}
void add(int &x, int y){
	x += y;
	x -= x >= P ? P : 0;
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read(), m = read(), s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	for (int i = 1; i <= n; ++ i){
		w[i] = read();
		if (a[i])
			s1 += w[i];
		else
			s2 += w[i];
	}
	for (int t = 1; t <= n; ++ t){
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		if (a[t]){
			for (int i = 0; i < m; ++ i)
				for (int j = 0; j <= i; ++ j)
					for (int k = 0; k <= j; ++ k)
						if (f[i][j][k]){
							int _s1 = s1 + j, _s2 = s2 - (i - j), inv = fpw(_s1 + _s2, P - 2);
							add(f[i + 1][j][k], 1LL * f[i][j][k] * _s2 % P * inv % P);
							add(f[i + 1][j + 1][k], 1LL * f[i][j][k] * (_s1 - (w[t] + k)) % P * inv % P);
							add(f[i + 1][j + 1][k + 1], 1LL * f[i][j][k] * (w[t] + k) % P * inv % P);
						}	
			int ans = 0;
			for (int j = 0; j <= m; ++ j)
				for (int k = 0; k <= j; ++ k)
					add(ans, 1LL * f[m][j][k] * (w[t] + k) % P);
			cout << ans << endl;
		}
		else{
			for (int i = 0; i < m; ++ i)
				for (int j = 0; j <= i; ++ j)
					for (int k = 0; k <= j; ++ k)
						if (f[i][j][k]){
							int _s1 = s1 + (i - j), _s2 = s2 - j, inv = fpw(_s1 + _s2, P - 2);
							add(f[i + 1][j][k], 1LL * f[i][j][k] * _s1 % P * inv % P);
							add(f[i + 1][j + 1][k], 1LL * f[i][j][k] * (_s2 - (w[t] - k)) % P * inv % P);
							add(f[i + 1][j + 1][k + 1], 1LL * f[i][j][k] * (w[t] - k) % P * inv % P);
						}	
			int ans = 0;
			for (int j = 0; j <= m; ++ j)
				for (int k = 0; k <= j; ++ k)
					add(ans, 1LL * f[m][j][k] * (w[t] - k) % P);
			cout << ans << endl;
		}
	}
}
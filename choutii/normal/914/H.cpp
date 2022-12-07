#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef unsigned int uint;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

const int MaxN = 205;
uint n, d, M, c[MaxN][MaxN], f[MaxN][MaxN], g[MaxN]; 

int main() {
	cin >> n >> d >> M;
	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
	}
	f[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < d; k++)
			(g[i - 1] += f[i - 1][k]) %= M;
		for (int j = 1; j < i; j++) 
			for (int k = 0; k < d; k++) 
				f[i][k + 1] = (f[i][k + 1] + (LL) f[i - j][k] * g[j] % M * c[i - 2][j - 1]) % M;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= d; j++) 
			for (int k = 0; j + k <= d; k++) {
				if(k == 1) continue;
				ans = (ans + (LL) f[i + 1][j] * f[n - i][k]) % M;
			}
	ans = (LL) ans * 2 * n * (n - 1) % M;
	cout << ans << endl;
	return 0;
}
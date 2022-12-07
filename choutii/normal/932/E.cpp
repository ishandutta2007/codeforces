#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 5555, P = 1e9 + 7;

int n, m, f[MaxN][MaxN];

int exp(int a, int n) {
	int res = 1; 
	for (; n > 0; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % P;
		a = (LL) a * a % P;
	}
	return res;
}

int main() {
	cin >> n >> m;
	f[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++)
			f[i][j] = ((LL) f[i - 1][j] * j + (LL) f[i - 1][j - 1] * (n - j + 1)) % P; 
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = (ans + (LL) exp(2, n - i) * f[m][i]) % P;
	cout << ans << endl;
	return 0;
}
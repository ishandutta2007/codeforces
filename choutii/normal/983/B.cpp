#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int N = 5005;

int n, a[N], b[N], f[N][N], g[N][N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++)
	 	read(a[i]), b[i] = b[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
		for (int l = 1; l <= n; l++) {
			int r = l + i - 1;
			f[l][r] = l == r ? a[r] : (f[l][r - 1] ^ f[l + 1][r]);
		}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			int j = i + k - 1;
			if(i == j) g[i][j] = f[i][j];
			else {
				g[i][j] = max(f[i][j], g[i + 1][j]);
				g[i][j] = max(g[i][j], g[i][j - 1]);
			}
		}
	
	}
	int q; read(q);
	while(q--) {
		int l, r; read(l); read(r);
		int ans = g[l][r];
		printf("%d\n", ans);
	}
	return 0;
}
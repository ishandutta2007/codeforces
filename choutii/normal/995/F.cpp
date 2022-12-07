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

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int mod = 1e9 + 7, NX = 3005;

int n, f[NX][NX], d; VI e[NX];

void dfs(int x) {
	for (int i = 1; i <= n + 1; i++)
		f[x][i] = 1; 
	for (int y : e[x]) {
		dfs(y);
		for (int i = 1; i <= n + 1; i++)
			f[x][i] = (LL) f[x][i] * f[y][i] % mod;
	}
	for (int i = 1; i <= n + 1; i++)
		(f[x][i] += f[x][i - 1]) %= mod; 
}

int p[NX], s[NX];
int exp(int a, int n) {
	int res = 1;
	for (; n; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % mod;
		a = (LL) a * a % mod;
	}
	return res;
}

int get_val(int n, int v) {
	if(v < n)
		return f[1][v];
	int value = 0;
	for (int i = 1; i <= n; i++) {
		int p = 1, q = 1;
		for (int j = 1; j <= n; j++)
			if(i != j) {
				p = (LL) p * (v - j) % mod;
				q = (LL) q * (i - j) % mod;
			}
		value = (value + (LL) f[1][i] * p % mod * exp(q, mod - 2)) % mod;
	}
	value = (value % mod + mod) % mod; 
	return value;
}
int main() {
	read(n); read(d);
	for (int i = 2, u; i <= n; i++) {
		read(u);
		e[u].pb(i);
	}
	dfs(1); 
	cout << get_val(n + 1, d) << "\n";
	return 0;
}
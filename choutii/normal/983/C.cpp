#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> vi;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int N = 2005, M = 4, L = 9;

vi trans[N]; 
map<vi, int> id;
int n, m, mx, a[N], b[N], to_a[N][L + 1], to_b[N][L + 1]; 
void dfs(int x, vi cur) {
	if(x == mx) {
		trans[++m] = cur;
		id[cur] = m;
		return;
	}
	for (int i = SZ(cur) ? cur.back() : 1; i <= L; i++) {
		vi nxt = cur; nxt.pb(i); dfs(x + 1, nxt);
	}
}

int f[N][L + 1][N];
int main() {
	for (mx = 1; mx <= 5; mx++) 
		dfs(1, {}); 
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]); read(b[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= L; j++) {
			vi u = trans[i], v = {};
			for (auto x : u)
				if(x != j)
					v.pb(x);
			to_a[i][j] = id[v];
			u = trans[i];
			if(SZ(u) != M) {
				u.pb(j); sort(ALL(u));
				to_b[i][j] = id[u]; 
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[1][1][1] = 0;
	for (int i = 1; i <= n + 1; i++) {
		for (int k = m; k >= 1; k--) {
			vi cur = trans[k];
			for (int j = 1; j <= L; j++) {
				for (auto l : cur) 
					cmin(f[i][l][to_a[k][l]], f[i][j][k] + abs(j - l));
				if(SZ(cur) != M && i <= n) 
					cmin(f[i + 1][a[i]][to_b[k][b[i]]], f[i][j][k] + abs(j - a[i]));
			}
		}
	}
	int ans = INT_MAX; 
	for (int j = 1; j <= L; j++)
		cmin(ans, f[n + 1][j][1]); 
	ans += (n << 1);
	cout << ans << endl;
	return 0;
}
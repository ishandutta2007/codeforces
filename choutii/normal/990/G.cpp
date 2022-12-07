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

const int NX = 201234;

int n, a[NX], fa[NX], sz[NX]; LL f[NX], g[NX]; VI vis, e[NX], ve[NX], pp[NX];
vector<pii> v[NX];
LL ans = 0;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return;
	vis.pb(u); vis.pb(v);
	fa[u] = v; ans += (LL) sz[u] * sz[v]; sz[v] += sz[u];	
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1, u, v; i < n; i++) {
		read(u); read(v);
		int g = __gcd(a[u], a[v]);
		e[u].pb(v); e[v].pb(u);
		::v[g].pb(mp(u, v));
	}
	for (int i = 1; i <= n; i++)
		ve[a[i]].pb(i);
		
	int m = *max_element(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) {
		vis.clear();
		for (int j = i; j <= m; j += i) {
			for (auto k : v[j])
				unite(k.X, k.Y);

			ans += SZ(ve[j]);
		}
		f[i] = ans; ans = 0;
		for (auto j : vis) fa[j] = j, sz[j] = 1;
	}
	
	for (int i = m; i; i--)
		for (int j = (i << 1); j <= m; j += i)
			f[i] -= f[j];
			
	for (int i = 1; i <= m; i++)
		if(f[i]) 
			printf("%d %lld\n", i, f[i]); 
	return 0;
}
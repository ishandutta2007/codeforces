#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;

int p[N];
int sz[N];

int find(int x){
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

bool unite(int u, int v){
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	p[v] = u;
	sz[u] += sz[v];
	return true;
}

int n, m;
int a[N];
vector<int> g[N];
int u[N];
pair<int, PII> e[N];
int ptr;

void dfs(int v){
	u[v] = 1;
	for(auto i: g[v]){
		if (!u[i]) dfs(i);
		if (v < n) e[ptr++] = {a[i] + a[v], {i, v}};
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, m) cin >> a[i + n];
	FOR(i, 0, n){
		int k; cin >> k;
		while(k--){
			int U; cin >> U; --U;
			g[i].PB(U + n);
			g[U + n].PB(i);
		}
	}

	LL Ans = 0;
	iota(p, p + n + m, 0);
	fill(sz, sz + n + m, 1);
	
	FOR(i, 0, n) if (!u[i]){
		ptr = 0;
		dfs(i);
		sort(e, e + ptr);
		reverse(e, e + ptr);
		
		FOR(j, 0, ptr){
			if (!unite(e[j].Y.X, e[j].Y.Y)){
				Ans += e[j].X;
			}
		}
	}
	
	cout << Ans << endl;	
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
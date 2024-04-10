//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt;
int col[MAXN], ind[MAXN], fa[MAXN];
vec<int> a[MAXN], id[MAXN];
vec<pii> tmp, G[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int find(int x) { 
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x];
}

void unity(int x, int y) {
	if(find(x) != find(y))
		fa[find(y)] = find(x);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= n; ++i) {
		a[i].resize(m + 1), id[i].resize(m + 1);
		for(int j = 1; j <= m; ++j)
			read(a[i][j]), id[i][j] = ++cnt;
	}
	for(int i = 1; i <= cnt; ++i) fa[i] = i;
	for(int i = 1; i <= n; ++i) {
		tmp.clear();
		for(int j = 1; j <= m; ++j)
			tmp.pb(mp(a[i][j], id[i][j]));
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j < m; ++j)
			if(tmp[j - 1].fst == tmp[j].fst)
				unity(tmp[j - 1].scd, tmp[j].scd);
	}
	for(int i = 1; i <= m; ++i) {
		tmp.clear();
		for(int j = 1; j <= n; ++j)
			tmp.pb(mp(a[j][i], id[j][i]));
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j < n; ++j)
			if(tmp[j - 1].fst == tmp[j].fst)
				unity(tmp[j - 1].scd, tmp[j].scd);
	}
	for(int i = 1; i <= n; ++i) {
		tmp.clear();
		for(int j = 1; j <= m; ++j)
			tmp.pb(mp(a[i][j], id[i][j]));
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j < m; ++j) {
			int w = tmp[j - 1].fst != tmp[j].fst ? 1 : 0;
			if(w) {
				G[find(tmp[j - 1].scd)].pb(mp(find(tmp[j].scd), w));
				ind[find(tmp[j].scd)]++;
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		tmp.clear();
		for(int j = 1; j <= n; ++j)
			tmp.pb(mp(a[j][i], id[j][i]));
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j < n; ++j) {
			int w = tmp[j - 1].fst != tmp[j].fst ? 1 : 0;
			if(w) {
				G[find(tmp[j - 1].scd)].pb(mp(find(tmp[j].scd), w));
				ind[find(tmp[j].scd)]++;
			}
		}
	}
	for(int i = 1; i <= cnt; ++i)
		if(!ind[i]) Q.push(i), col[i] = 1;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0, to; i < G[x].size(); ++i) { 
			to = G[x][i].fst;
			col[to] = max(col[to], col[x] + G[x][i].scd);
			if(!(--ind[to])) Q.push(to);
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			printf("%d%c", col[find(id[i][j])], " \n"[j == m]);
	return 0;
}
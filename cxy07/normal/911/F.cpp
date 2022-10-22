//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, A, B, Ans;
int dis[MAXN], p[MAXN][21], dep[MAXN], ind[MAXN];
bool on[MAXN], vis[MAXN];
vec<int> G[MAXN];
queue<int> Q;
vec<tuple<int, int, int>> ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x, int fa) {
	dis[x] = dis[fa] + 1;
	for(auto to : G[x]) if(to ^ fa) DFS(to, x);
}

void GetLCA(int x, int fa) {
	p[x][0] = fa; dep[x] = dep[fa] + 1;
	for(int i = 1; i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(auto to : G[x]) if(to ^ fa) GetLCA(to, x);
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; --i) if(dep[p[x][i]] >= dep[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; --i)
		if(p[x][i] ^ p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];
}

int DIS(int x, int y) {
	int lca = LCA(x, y);
	return dep[x] + dep[y] - (dep[lca] << 1);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		ind[x]++, ind[y]++;
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	A = max_element(dis + 1, dis + n + 1) - dis;
	memset(dis, 0, sizeof dis);
	DFS(A, 0);
	B = max_element(dis + 1, dis + n + 1) - dis;
	GetLCA(1, 0);
	int a = A, b = B;
	while(a ^ b) {
		on[a] = on[b] = true;
		if(dep[a] < dep[b]) swap(a, b);
		a = p[a][0]; on[a] = true;
	}
	for(int i = 1; i <= n; ++i)
		if(!on[i] && ind[i] == 1) Q.push(i);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		if(vis[x] || on[x]) continue;
		vis[x] = true;
		int da = DIS(x, A), db = DIS(x, B);
		if(da > db) {
			Ans += da;
			ans.pb(make_tuple(x, A, x));
		} else {
			Ans += db;
			ans.pb(make_tuple(x, B, x));
		}
		for(auto to : G[x]) {
			if(vis[to] || on[to]) continue;
			ind[to]--;
			if(ind[to] == 1) Q.push(to);
		}
	}
	//int d = DIS(A, B);
	//Ans += (d + 1) * d / 2;
	while(A ^ B) {
		if(dep[A] < dep[B]) swap(A, B);
		ans.pb(make_tuple(A, B, A));
		Ans += DIS(A, B);
		A = p[A][0];
	}
	printf("%lld\n", Ans);
	for(auto x : ans)
		printf("%lld %lld %lld\n", get<0>(x), get<1>(x), get<2>(x));
	return 0;
}
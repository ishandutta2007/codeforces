//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

const int MAXN = 6e5 + 10;
const int MAXM = 2e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXM << 1], to[MAXM << 1], id[MAXM << 1];
	void add(int x, int y, int i = 0) {
		nxt[++siz] = head[x];
		to[siz] = y, id[siz] = i, head[x] = siz;
	}
} e;

int n, m, Ans, aux;
int X[MAXN], Y[MAXN], W[MAXN];
int ind[MAXN], dir[MAXN];
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x) {
	for(int &i = e.head[x], to, id; i; i = e.nxt[i]) {
		to = e.to[i], id = e.id[i];
		if(vis[i] || vis[i ^ 1]) continue;
		vis[i] = vis[i ^ 1] = true;
		DFS(to); dir[abs(id)] = 1 + (id < 0);
	}
}

signed main () {
#ifdef FILE
	freopen("CF1610F.in", "r", stdin);
	freopen("CF1610F.out", "w", stdout);
#endif
	read(n), read(m); e.siz = 1, aux = (n << 1) + 1;
	for(int i = 1; i <= m; ++i) {
		read(X[i]), read(Y[i]), read(W[i]);
		ind[X[i]] += W[i], ind[Y[i]] += W[i];
	}
	for(int i = 1; i <= n; ++i) Ans += (ind[i] & 1);
	memset(ind, 0, sizeof ind);
	for(int i = 1; i <= m; ++i) {
		if(W[i] == 1) {
			ind[X[i]]++, ind[Y[i]]++;
			e.add(X[i], Y[i], i), e.add(Y[i], X[i], -i);
		} else {
			ind[X[i] + n]++, ind[Y[i] + n]++;
			e.add(X[i] + n, Y[i] + n, i), e.add(Y[i] + n, X[i] + n, -i);
		}
	}
	for(int i = 1; i <= n; ++i)
		if((ind[i] & 1) && (ind[i + n] & 1)) {
			e.add(i, i + n), e.add(i + n, i);
			ind[i]++, ind[i + n]++;
		}
	for(int i = 1; i <= n; ++i) {
		if(ind[i] & 1) e.add(aux, i), e.add(i, aux);
		if(ind[i + n] & 1) e.add(aux, i + n), e.add(i + n, aux);
	}
	for(int i = 1; i <= (n << 1) + 1; ++i) DFS(i);
	printf("%d\n", Ans);
	for(int i = 1; i <= m; ++i) printf("%d", dir[i]);
	memset(ind, 0, sizeof ind);
	for(int i = 1; i <= m; ++i) {
		if(dir[i] == 2) ind[X[i]] += W[i], ind[Y[i]] -= W[i];
		else ind[X[i]] -= W[i], ind[Y[i]] += W[i];
	}
	for(int i = 1; i <= n; ++i) if(abs(ind[i]) == 1) --Ans;
	assert(!Ans);
	return 0;
}
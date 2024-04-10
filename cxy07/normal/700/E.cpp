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

const int MAXN = 4e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans = 1;
int ch[MAXN][26], len[MAXN], fa[MAXN], pos[MAXN], las = 1, cnt = 1;
int root[MAXN], sum[MAXN * 40], ls[MAXN * 40], rs[MAXN * 40], siz;
int dp[MAXN], l[MAXN], per[MAXN];
char s[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Insert(int &x, int l, int r, int p) {
	if(!x) x = ++siz;
	if(l == r) return sum[x]++, void();
	int mid = (l + r) >> 1;
	if(p <= mid) Insert(ls[x], l, mid, p);
	else Insert(rs[x], mid + 1, r, p);
	sum[x] = sum[ls[x]] + sum[rs[x]];
}

int Merge(int a, int b) {
	if(!a || !b) return (a | b);
	int now = ++siz;
	ls[now] = Merge(ls[a], ls[b]);
	rs[now] = Merge(rs[a], rs[b]);
	sum[now] = sum[ls[now]] + sum[rs[now]];
	return now;
}

int query(int x, int l, int r, int L, int R) {
	if(!x || L > R) return 0;
	if(L <= l && r <= R) return sum[x];
	int mid = (l + r) >> 1, res = 0;
	if(L <= mid) res += query(ls[x], l, mid, L, R);
	if(res) return res;
	if(R > mid) res += query(rs[x], mid + 1, r, L, R);
	return res;
}

void Extend(int c, int ps) {
	int p = las, np; np = las = ++cnt;
	len[np] = len[p] + 1, pos[np] = ps; 
	Insert(root[cnt], 1, n, ps);
	for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
	if(!p) fa[np] = 1;
	else {
		int q = ch[p][c];
		if(len[q] == len[p] + 1) fa[np] = q;
		else {
			int nq = ++cnt;
			len[nq] = len[p] + 1, fa[nq] = fa[q], pos[nq] = pos[q];
			memcpy(ch[nq], ch[q], sizeof ch[q]);
			fa[np] = fa[q] = nq;
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}
	}
}

bool cmp(int a, int b) {return len[a] < len[b];}

void DFS(int x) {
	for(auto to : G[x]) DFS(to), root[x] = Merge(root[x], root[to]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) Extend(s[i] - 'a', i);
	for(int i = 1; i <= cnt; ++i) per[i] = i;
	for(int i = 2; i <= cnt; ++i) G[fa[i]].pb(i);
	DFS(1), sort(per + 1, per + cnt + 1, cmp);
	for(int i = 2, x; i <= cnt; ++i) {
		x = per[i];
		if(fa[x] == 1) {dp[x] = 1, l[x] = x; continue;}
		int ok = query(root[l[fa[x]]], 1, n, pos[x] - len[x] + len[l[fa[x]]], pos[x] - 1);
		if(ok) dp[x] = dp[fa[x]] + 1, l[x] = x, Ans = max(Ans, dp[x]);
		else dp[x] = dp[fa[x]], l[x] = l[fa[x]];
	}
	printf("%d\n", Ans);
	return 0;
}
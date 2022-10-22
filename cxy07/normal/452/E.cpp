//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 6e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SAM {
	int len, fa;
	int ch[30];
} T[MAXN];

int n, m;
int las = 1, tot = 1;
int l[4], pp[4], Len;
int sum[MAXN * 20], ls[MAXN * 20], rs[MAXN * 20], cnt;
int root[MAXN], sav[MAXN];
LL ans[MAXN];
vec<int> G[MAXN];
string s[4], S;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void Update(int &x, int l, int r, int pos, int v) {
	if(!x) x = ++cnt;
	if(l == r) {
		sum[x] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) Update(ls[x], l, mid, pos, v);
	else Update(rs[x], mid + 1, r, pos, v);
	sum[x] = sum[ls[x]] + sum[rs[x]];
}

int Query(int x, int l, int r, int L, int R) {
	if(!x) return 0;
	if(L <= l && r <= R) return sum[x];
	int mid = (l + r) >> 1, res = 0;
	if(L <= mid) res += Query(ls[x], l, mid, L, R);
	if(R > mid) res += Query(rs[x], mid + 1, r, L, R);
	return res;
}

int Merge(int &x, int &y) {
	if(!x || !y) return (x | y);
	sum[x] += sum[y];
	ls[x] = Merge(ls[x], ls[y]);
	rs[x] = Merge(rs[x], rs[y]);
	return x;
}

void Insert(int x, int pos) {
	int np, p = las;
	np = las = ++tot;
	T[np].len = T[p].len + 1;
	sav[tot] = pos;
	for(; p && !T[p].ch[x]; p = T[p].fa) T[p].ch[x] = np;
	if(!p) T[np].fa = 1;
	else {
		int q = T[p].ch[x];
		if(T[q].len == T[p].len + 1) T[np].fa = q;
		else {
			int nq = ++tot;
			T[nq] = T[q];
			T[nq].len = T[p].len + 1;
			T[q].fa = T[np].fa = nq;
			for(; p && T[p].ch[x] == q; p = T[p].fa) T[p].ch[x] = nq;
		}
	}
}

void DFS(int x) {
	if(sav[x] != -1) Update(root[x], 0, Len, sav[x], 1);
	for(auto to : G[x]) {
		DFS(to);
		root[x] = Merge(root[x], root[to]);
	}
	LL sum[4], res = 1;
	for(int i = 1; i <= 3; ++i) {
		sum[i] = Query(root[x], 0, Len, pp[i], pp[i] + l[i] - 1);
		(res *= sum[i]) %= mod;
	}
	(ans[T[x].len + 1] -= res) %= mod;
	(ans[T[T[x].fa].len + 1] += res) %= mod;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> s[1] >> s[2] >> s[3];
	S = s[1] + "{" + s[2] + "|" + s[3];
	for(int i = 1; i <= 3; ++i) l[i] = s[i].length();
	pp[1] = 0, pp[2] = l[1] + 1, pp[3] = l[1] + l[2] + 2;
	assert(S[pp[1]] == s[1][0]);
	assert(S[pp[2]] == s[2][0]);
	assert(S[pp[3]] == s[3][0]);
	Len = S.length();
	memset(sav, -1, sizeof sav);
	for(int i = 0; i < Len; ++i)
		Insert(S[i] - 'a', i);
	for(int i = 2; i <= tot; ++i) G[T[i].fa].pb(i);
	DFS(1);
	for(int i = 1; i <= min(l[1], min(l[2], l[3])); ++i) {
		(ans[i] += ans[i - 1]) %= mod;
		ans[i] = (ans[i] % mod + mod) % mod;
		printf("%lld ", ans[i]);
	}
	return 0;
}
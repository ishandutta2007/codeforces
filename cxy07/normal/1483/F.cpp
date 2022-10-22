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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct FenwickTree {
	int a[MAXN];
	void add(int x, int v) { for(; x < MAXN; x += lowbit(x)) a[x] += v; }
	int ask(int x) { int r = 0; for(; x; x -= lowbit(x)) r += a[x]; return r; }
	int query(int l, int r) { return ask(r) - ask(l - 1); }
} T;

int n, m, tcnt, Ans;
int ch[MAXN][26], fail[MAXN], pos[MAXN], Id[MAXN][2];
int dfn[MAXN], siz[MAXN], dfnc;
int at[MAXN], who[MAXN];
vec<int> loc[MAXN], G[MAXN];
set<pii> S;
string s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Insert(int x) {
	int cur = 0;
	for(int i = 0; i < (int)s[x].size(); ++i) {
		int &to = ch[cur][s[x][i] - 'a'];
		if(!to) to = ++tcnt;
		cur = to; loc[x].pb(cur);
	}
	assert(!Id[cur][1]); Id[cur][1] = x;
}

void build() {
	queue<int> Q;
	for(int i = 0; i < 26; ++i)
		if(ch[0][i]) Q.push(ch[0][i]);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < 26; ++i) {
			if(ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], Q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}

void DFS(int x) {
	if(!Id[x][1]) Id[x][1] = Id[x][0];
	dfn[x] = ++dfnc, siz[x] = 1;
	for(auto to : G[x]) { Id[to][0] = Id[x][1]; DFS(to); siz[x] += siz[to]; }
}

int calc(int now) {
	vec<int> v, v2; v.clear(), v2.clear();
	assert(Id[loc[now].back()][1] == now);
	for(int i = 0, t; i < (int)loc[now].size(); ++i) {
		t = Id[loc[now][i]][i < (int)loc[now].size() - 1];
		who[i] = t; if(t) v.pb(t);
	}
	if(!v.size()) return 0;
	sort(v.begin(), v.end(), [&](int a, int b) { return s[a].size() > s[b].size(); });
	for(auto p : v) {
		int t = loc[p].back();
		if(T.query(dfn[t], dfn[t] + siz[t] - 1)) continue;
		T.add(dfn[t], 1); v2.pb(p);
	}
	v.swap(v2); S.clear();
	for(auto p : v) {
		T.add(dfn[loc[p].back()], -1);
		at[p] = -1, S.insert(mp(-1, p));
	}
	for(int i = 0, t, L; i < (int)loc[now].size(); ++i) {
		t = who[i];
		if(!S.count(mp(at[t], t))) continue;
		S.erase(mp(at[t], t));
		L = i - s[t].size() + 1;
		while(S.size()) {
			auto it = prev(S.end());
			if((it->fst) >= L) S.erase(it);
			else break;
		}
		at[t] = L; S.insert(mp(at[t], t));
	}
	return S.size();
}

signed main () {
#ifdef FILE
	freopen("CF1483F.in", "r", stdin);
	freopen("CF1483F.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> s[i], Insert(i);
	build();
	for(int i = 1; i <= tcnt; ++i) G[fail[i]].pb(i);
	DFS(0);
	for(int i = 1; i <= n; ++i) Ans += calc(i);
	cout << Ans << endl;
	return 0;
}
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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct QS {
	int k, L, R, id;
	QS(int _k = 0, int l = 0, int r = 0, int i = 0) :
		k(_k), L(l), R(r), id(i) {}
};

int n, m, lim;
int ch[MAXN][26], End[MAXN], fail[MAXN];
int Hugeid[MAXN], hidc, Hv[MAXN];
int dfn[MAXN], siz[MAXN], dfnc;
int rt, chc;
LL Ans[MAXN], Hsum[MAXN];
string s[MAXN];
vec<QS> Huge[MAXN], Q[MAXN];
vec<int> G[MAXN];

struct fenwick {
	LL a[MAXN];
	void add(int x, LL v) {for(; x <= dfnc; x += lowbit(x)) a[x] += v;}
	int ask(int x) {LL res = 0; for(; x; x -= lowbit(x)) res += a[x]; return res;}
} T;

void Insert(int x) {
	int now = rt, len = s[x].length();
	for(int i = 0; i < len; ++i) {
		int &to = ch[now][s[x][i] - 'a'];
		if(!to) to = ++chc;
		now = to;
	}
	End[x] = now;
}

void Ac_init() {
	queue<int> Q; while(Q.size()) Q.pop();
	for(int i = 0; i < 26; ++i)
		if(ch[0][i]) fail[ch[0][i]] = 0, Q.push(ch[0][i]);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < 26; ++i) {
			if(ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], Q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}

void Getdfn(int x) {
	siz[x] = 1, dfn[x] = ++dfnc;
	for(auto to : G[x]) {
		Getdfn(to);
		siz[x] += siz[to];
	}
}

void GetHson(int x) {
	for(auto to : G[x]) {
		GetHson(to);
		Hv[x] += Hv[to];
	}
}

void DoHuge(int x) {
	if(!Huge[x].size()) return;
	memset(Hsum, 0, sizeof Hsum), memset(Hv, 0, sizeof Hv);
	int now = 0, len = s[x].length();
	for(int i = 0; i < len; ++i)
		Hv[now = ch[now][s[x][i] - 'a']]++;
	GetHson(0);
	for(int p = 1; p <= n; ++p) Hsum[p] = Hsum[p - 1] + Hv[End[p]];
	for(auto q : Huge[x])
		Ans[q.id] += Hsum[q.R] - Hsum[q.L - 1];
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	ios :: sync_with_stdio(0);
	cin >> n >> m; int sum = 0;
	for(int i = 1; i <= n; ++i) cin >> s[i], Insert(i), sum += s[i].length();
	lim = sum / sqrt(m * log(sum) / log(2));
	Ac_init();
	for(int i = 1; i <= chc; ++i) G[fail[i]].pb(i);
	Getdfn(0);
	for(int i = 1, k, l, r; i <= m; ++i) {
		cin >> l >> r >> k;
		if(s[k].length() > lim) {Huge[k].pb(QS(k, l, r, i)); continue;}
		if(l > 1) Q[l - 1].pb(QS(k, 0, 0, -i));
		Q[r].pb(QS(k, 0, 0, i));
	}
	for(int i = 1; i <= n; ++i)
		if(s[i].length() > lim) DoHuge(i);
	for(int i = 1; i <= n; ++i) {
		T.add(dfn[End[i]], 1); T.add(dfn[End[i]] + siz[End[i]], -1);
		for(auto q : Q[i]) {
			int opt = q.id < 0 ? -1 : 1, id = abs(q.id), x = q.k;
			int now = 0, len = s[x].length();
			for(int j = 0; j < len; ++j)
				Ans[id] += opt * T.ask(dfn[now = ch[now][s[x][j] - 'a']]);
		}
	}
	for(int i = 1; i <= m; ++i) cout << Ans[i] << endl;
	return 0;
}
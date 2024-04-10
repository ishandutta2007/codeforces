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

const int MAXN = 810;
const int MAXS = 1e7 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int G[MAXN][MAXN];
int ch[MAXS][2], id[MAXS], fail[MAXS], cnt;
int f[MAXS], mch[MAXN], mch2[MAXN];
bool vis[MAXN], vl[MAXN], vr[MAXN];
string s[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Insert(int x) {
	int now = 0, len = s[x].length();
	for(int i = 0; i < len; ++i) {
		int &to = ch[now][s[x][i] - 'a'];
		if(!to) to = ++cnt;
		now = to;
	}
	id[now] = x;
}

int find(int x) {
	if(f[x] != x) return f[x] = find(f[x]);
	return x;
}

void unity(int x, int y) { 
	x = find(x), y = find(y);
	if(x != y) f[x] = y;
}

void build() {
	for(int i = 0; i <= 1; ++i)
		if(ch[0][i]) fail[ch[0][i]] = 0, Q.push(ch[0][i]);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i <= 1; ++i) {
			if(ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], Q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
	for(int i = 1; i <= cnt; ++i) f[i] = i;
	for(int i = 1; i <= cnt; ++i) {
		if(id[i]) f[i] = i;
		else if(!f[fail[i]]) f[i] = 0;
		else unity(i, fail[i]);
	}
}

void GetG(int x) {
	int now = 0, len = s[x].length();
	for(int i = 0, to; i < len; ++i) {
		to = ch[now][s[x][i] - 'a'];
		if(id[to] && id[to] != x) G[x][id[to]] = true;
		if(fail[to] && f[fail[to]] && find(fail[to]))
			G[x][id[find(fail[to])]] = true;
		now = to;
	}
}

bool DFS(int x) {
	for(int i = 1; i <= n; ++i) {
		if(!G[x][i] || vis[i]) continue;
		vis[i] = true;
		if(!mch[i] || DFS(mch[i])) return mch[i] = x, true;
	}
	return false;
}

void DFS2(int x) {
	if(vl[x]) return;
	vl[x] = true;
	for(int i = 1; i <= n; ++i) {
		if(!G[x][i] || vr[i] || mch2[x] == i) continue;
		vr[i] = true;
		if(mch[i]) DFS2(mch[i]);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	ios :: sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> s[i], Insert(i);
	build();
	for(int i = 1; i <= n; ++i) GetG(i);
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				G[i][j] |= (G[i][k] & G[k][j]);
	for(int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		if(DFS(i)) Ans++;
	}
	cout << n - Ans << endl;
	for(int i = 1; i <= n; ++i)
		if(mch[i]) mch2[mch[i]] = i;
	for(int i = 1; i <= n; ++i)
		if(!mch2[i]) DFS2(i);
	for(int i = 1; i <= n; ++i)
		if(vl[i] && !vr[i]) cout << i << ' ';
	return 0;
}
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

const int MAXN = 510;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, Ans;
int dis[MAXN], pre[MAXN];
bool in[MAXN];
vec<int> G[MAXN], now, tmp;
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Go(int x) {
	if(!x) return;
	Go(pre[x]); int v = 0, s;
	for(int j = 0; j <= min(k, pre[x]); ++j) {
		if(pre[x] - j + (k - j) > n) continue;
		if(k - j > n - pre[x]) continue;
		if(pre[x] - j + (k - j) == x) { v = j; break; }
	}
	cout << "? ";
	for(int i = (int)now.size() - 1; i >= (int)now.size() - v; --i)
		cout << now[i] << ' ';
	tmp.clear();
	for(int i = 1, c = k - v; i <= n; ++i) 
		if(!in[i] && c >= 1) tmp.pb(i), c--, cout << i << ' ';
	cout << endl; cin >> s; Ans ^= s;
	for(int i = 1; i <= v; ++i) {
		in[now.back()] = false;
		now.pop_back();
	}
	for(auto x : tmp) in[x] = true, now.pb(x);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k); memset(dis, 0x3f, sizeof dis);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= min(k, i); ++j) {
			if(i - j + (k - j) > n) continue;
			if(k - j > n - i) continue;
			G[i].pb(i - j + (k - j));
		}
	} 
	dis[0] = 0, Q.push(0);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(auto to : G[x])
			if(dis[to] == dis[MAXN - 1]) {
				dis[to] = dis[x] + 1, pre[to] = x;
				Q.push(to);
			}
	}
	if(dis[n] == dis[MAXN - 1]) return puts("-1"), 0;
	Go(n); cout << "! " << Ans << endl; 
	return 0;
}
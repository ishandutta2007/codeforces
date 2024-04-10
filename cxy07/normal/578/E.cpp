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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct seq {
	int st, ed;
	vec<int> pos;
} s[MAXN];

int n, m, cnt, fir;
int a[MAXN], cc[2];
char ss[MAXN];
vec<int> opt[2][2], unite[4];
vec<int> Ans, Index[2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", ss + 1); n = strlen(ss + 1);
	for(int i = 1; i <= n; ++i) cc[a[i] = (ss[i] == 'R')]++;
	if(cc[0] == cc[1]) fir = -1;
	else fir = cc[1] > cc[0] ? 1 : 0;
	for(int i = 1, p; i <= n; ++i) {
		if(Index[a[i] ^ 1].size()) {
			p = Index[a[i] ^ 1].back();
			Index[a[i] ^ 1].pop_back();
			s[p].ed = a[i]; s[p].pos.pb(i); Index[a[i]].pb(p);
		} else {
			s[++cnt].st = a[i]; s[cnt].ed = a[i];
			s[cnt].pos.pb(i);
			Index[a[i]].pb(cnt);
		}
	}
	printf("%d\n", cnt - 1);
	for(int i = 1; i <= cnt; ++i) {
		opt[s[i].st][s[i].ed].pb(i);
		//for(auto x : s[i].pos) cout << x << ' ';
		//cout << endl;
	}
	if(opt[1][0].size() && opt[0][1].size() && !opt[0][0].size() && !opt[1][1].size()) {
		int idx = opt[1][0].back(); int posx = s[idx].pos.back();
		int idy = opt[0][1].back(); int posy = s[idy].pos.back();
		int d = 0;
		if(posx > posy) swap(idx, idy), swap(posx, posy), d ^= 1;
		s[idx].pos.pb(posy); s[idy].pos.pop_back();
		opt[d][d ^ 1].pop_back();
		opt[d ^ 1][d].pop_back();
		opt[d ^ 1][d ^ 1].pb(idx);
		opt[d][d].pb(idy);
	}
	int d = 0;
	if(!opt[1][1].size()) d ^= 1;
	for(auto x : opt[d][d])
		for(int y : s[x].pos) printf("%d ", y);
	for(auto x : opt[d ^ 1][d])
		for(int y : s[x].pos) printf("%d ", y);
	for(auto x : opt[d ^ 1][d ^ 1])
		for(int y : s[x].pos) printf("%d ", y);
	for(auto x : opt[d][d ^ 1])
		for(int y : s[x].pos) printf("%d ", y);
	return 0;
}
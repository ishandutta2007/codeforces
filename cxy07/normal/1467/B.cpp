//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a[MAXN], cnt, ans;
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void calc(int p, int v) {
	int now = cnt;
	for(int i = max(2, p - 1); i <= min(n - 1, p + 1); ++i) {
		if(a[i - 1] < a[i] && a[i] > a[i + 1]) now--;
		if(a[i - 1] > a[i] && a[i] < a[i + 1]) now--;
	}
	a[p] = v;
	for(int i = max(2, p - 1); i <= min(n - 1, p + 1); ++i) {
		if(a[i - 1] < a[i] && a[i] > a[i + 1]) now++;
		if(a[i - 1] > a[i] && a[i] < a[i + 1]) now++;
	}
	ans = min(ans, now);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); cnt = ans = 0;
		for(int i = 1; i <= n; ++i) read(a[i]);
		for(int i = 2; i < n; ++i) {
			if(a[i - 1] < a[i] && a[i] > a[i + 1]) cnt++;
			if(a[i - 1] > a[i] && a[i] < a[i + 1]) cnt++;
		}
		ans = cnt;
		for(int i = 1, sav; i <= n; ++i) {
			sav = a[i];
			calc(i, a[i - 1]);
			a[i] = sav;
			calc(i, a[i + 1]);
			a[i] = sav;
		}
		cout << ans << endl;
	}
	return 0;
}
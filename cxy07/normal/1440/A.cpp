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
#define vec vector

const int MAXN = 1010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, m;
int n, c0, c1, h, b0, b1;
char s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> T;
	while(T--) {
		cin >> n >> c0 >> c1 >> h;
		b0 = b1 = 0;
		cin >> s + 1;
		for(int i = 1; i <= n; ++i)
			if(s[i] == '0') b0++;
			else b1++;
		int ans = INF;
		for(int i = 0; i <= n; ++i) {
			int c = 0;
			if(b0 < i) c += h * (i - b0);
			if(b1 < (n - i)) c += h * ((n - i) - b1);
			//cout << i << ' ' << c << endl;
			ans = min(ans, c + i * c0 + (n - i) * c1);
		}
		cout << ans << endl;
	}
	return 0;
}
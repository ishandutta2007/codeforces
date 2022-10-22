//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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
const int INF = 2e16;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int m, tmp = INF, tot = 0;
int a[4], n[4], ans = 0;
int v[4][2];

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
	for(int i = 1; i <= 3; ++i) cin >> n[i];
	for(int i = 1; i <= 3; ++i)
		for(int j = 0; j <= 1; ++j) v[i][j] = (int)(2e9);
	for(int i = 1; i <= 3; ++i) {
		int nn = n[i];
		for(int j = 1, x; j <= nn; ++j) {
			cin >> x;
			tot += x;
			a[i] += x;
			if(x < v[i][0]) swap(v[i][0], v[i][1]), v[i][0] = x;
			else if(x < v[i][1]) v[i][1] = x;
		}
	}
	for(int i = 1; i <= 3; ++i) {
		ans = max(ans, tot - 2 * a[i]);
		for(int j = 1; j <= 3; ++j) {
			if(i == j) continue;
			ans = max(ans, tot - 2 * (v[i][0] + v[j][0]));
		}
	}
	cout << ans << endl;
	return 0;
}
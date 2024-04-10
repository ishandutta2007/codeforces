//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 2e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, l;
int sum[MAXN];
int Lx = -INF, Rx = INF, Ly = -INF, Ry = INF;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void NO() {puts("NO"), exit(0);}

struct NODE {
	int t, x, y, a, b;
	void read() {
		::read(t), ::read(x), ::read(y);
		if((t + x + y) % 2)	NO();
		a = t / l, b = t % l;
		int tmpx = x, tmpy = y;
		x = (tmpx + tmpy + t) >> 1, y = (tmpy - tmpx + t) >> 1;
	}
	bool operator < (const NODE &tp) const {return b < tp.b;}
} s[MAXN];

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(l);
	for(int i = 1; i <= n; ++i) s[i].read();
	sort(s + 1, s + n + 1);
	s[++n].a = -1; s[n].b = l;
	for(int i = 1; i <= n; ++i) {
		int A = s[i].a - s[i - 1].a;
		int B = s[i].b - s[i - 1].b;
		assert(B >= 0);
		if(!A) {
			if(s[i].x - s[i - 1].x > B || s[i].x < s[i - 1].x) NO();
			if(s[i].y - s[i - 1].y > B || s[i].y < s[i - 1].y) NO();
		} 
		if(A > 0) {
			Lx = max(Lx, (int)ceil(1.0L * (s[i].x - s[i - 1].x - B) / A));
			Rx = min(Rx, (int)floor(1.0L * (s[i].x - s[i - 1].x) / A));
			Ly = max(Ly, (int)ceil(1.0L * (s[i].y - s[i - 1].y - B) / A));
			Ry = min(Ry, (int)floor(1.0L * (s[i].y - s[i - 1].y) / A));
		}
		if(A < 0) {
			Lx = max(Lx, (int)ceil(1.0L * (s[i].x - s[i - 1].x) / A));
			Rx = min(Rx, (int)floor(1.0L * (s[i].x - s[i - 1].x - B) / A));
			Ly = max(Ly, (int)ceil(1.0L * (s[i].y - s[i - 1].y) / A));
			Ry = min(Ry, (int)floor(1.0L * (s[i].y - s[i - 1].y - B) / A));
		}
	}
	if(Lx > Rx || Ly > Ry) NO();
	for(int i = 1; i <= n; ++i) {
		int dx = (s[i].x - s[i].a * Lx) - (s[i - 1].x - s[i - 1].a * Lx);
		int dy = (s[i].y - s[i].a * Ly) - (s[i - 1].y - s[i - 1].a * Ly);
		int x = 0, y = 0;
		for(int j = 1; j <= s[i].b - s[i - 1].b; ++j) {
			if(x < dx) ++x, putchar(y < dy ? ++y, 'U' : 'R');
			else putchar(y < dy ? ++y, 'L' : 'D');
		}
	}
	return 0;
}
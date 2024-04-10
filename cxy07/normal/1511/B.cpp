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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a, b, c;
int p[10];
int pr[10] = {1, 3, 13, 233, 1009, 99991, 100003, 3991681, 19260817, 998244353};

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
	read(T);
	p[0] = 1;
	for(int i = 1; i <= 9; ++i) p[i] = p[i - 1] * 10;
	while(T--) {
		read(a), read(b), read(c);
		if(a == b) cout << pr[a - c + 1] * p[c - 1] << ' ' << (pr[b - c + 1] + 1) * p[c - 1] << endl;
		else cout << pr[a - c + 1] * p[c - 1] << ' ' << pr[b - c + 1] * p[c - 1] << endl;
	}
}
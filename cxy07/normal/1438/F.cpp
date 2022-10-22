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

const int MAXN = 20;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, h;
int cnt[(1 << MAXN) + 10];
int p1, p2;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int randint(int l, int r) {
	return rand() % (r - l + 1) + l;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	srand(5224999);
	cin >> h;
	n = (1 << h) - 1;
	for(int i = 1, x, y, z, lca; i <= 420; ++i) {
		x = randint(1, n);
		y = randint(1, n);
		while(y == x) y = randint(1, n);
		z = randint(1, n);
		while(z == x || z == y) z = randint(1, n);
		assert(x != y && y != z && z != x);
		cout << "? " << x << ' ' << y << ' ' << z << endl;
		cout.flush();
		cin >> lca;
		cnt[lca]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(cnt[i] > cnt[p1]) p2 = p1, p1 = i;
		else if(cnt[i] > cnt[p2]) p2 = i;
	}
	assert(p1 && p2);
	for(int i = 1, lca; i <= n; ++i) {
		if(i == p1 || i == p2) continue;
		cout << "? " << p1 << ' ' << p2 << ' ' << i << endl;
		cout.flush();
		cin >> lca;
		if(i == lca) {
			cout << "! " << i << endl;
			cout.flush();
			return 0;
		}
	}
	return 0;
}
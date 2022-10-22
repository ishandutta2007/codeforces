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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int xr[MAXN], a[MAXN], sum[MAXN];
int buk[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int AND(int x, int y) {
	int res;
	cout << "AND" << ' ' << x << ' ' << y << endl;
	cout.flush();
	cin >> res;
	return res;
}

int OR(int x, int y) {
	int res;
	cout << "OR" << ' ' << x << ' ' << y << endl;
	cout.flush();
	cin >> res;
	return res;
}

int XOR(int x, int y) {
	int res;
	cout << "XOR" << ' ' << x << ' ' << y << endl;
	cout.flush();
	cin >> res;
	return res;
}

void ANSWER() {
	cout << "! ";
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	cout.flush();
}

void same(int x, int y) {
	a[x] = a[y] = AND(x, y);
	for(int i = x - 1; i >= 1; --i)
		a[i] = xr[i] ^ a[i + 1];
	for(int i = x; i < n; ++i)
		a[i + 1] = a[i] ^ xr[i];
	ANSWER();
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> n;
	for(int i = 1; i < n; ++i)
		xr[i] = XOR(i, i + 1);
	for(int i = 1; i < n; ++i) {
		if(!xr[i]) {
			same(i, i + 1);
			return 0;
		}
	}
	buk[0] = 1;
	for(int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] ^ xr[i];
		if(buk[sum[i]]) {
			same(buk[sum[i]], i + 1);
			return 0;
		}
		buk[sum[i]] = i + 1;
	}
	memset(buk, 0, sizeof buk);
	buk[0] = 1;
	int pos1 = 0, pos2 = 0, vhigh, vlow;
	for(int i = 1; i < n; ++i) {
		if(buk[sum[i] ^ 1]) {
			pos1 = buk[sum[i] ^ 1];
			pos2 = i + 1;
			break;
		}
		buk[sum[i]] = i + 1;
	}
	assert(pos1 && pos2);
	vhigh = AND(pos1, pos2);
	memset(buk, 0, sizeof buk);
	for(int i = 0; i < n; ++i) {
		if((sum[i] ^ sum[pos1 - 1]) == n / 2) {
			vlow = AND(i + 1, pos1);
			break;
		}
	}
	a[pos1] = (vhigh | vlow);
	for(int i = pos1 - 1; i >= 1; --i)
		a[i] = xr[i] ^ a[i + 1];
	for(int i = pos1; i < n; ++i)
		a[i + 1] = a[i] ^ xr[i];
	ANSWER();
	return 0;
}
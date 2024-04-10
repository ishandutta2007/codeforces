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
char s[MAXN], tmp[4];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool chk(int len) {
	for(int i = 1; i <= n - len + 1; ++i) {
		bool flag = true;
		for(int j = 1; j <= len; ++j)
			if(s[i + j - 1] != tmp[j]) {flag = false; break;}
		if(flag) return false;
	}
	for(int i = 1; i <= len; ++i) putchar(tmp[i]);
	putchar('\n');
	return true;
}

bool DFS(int x, int len) {
	if(x > len) return chk(len);
	for(int i = 0; i < 26; ++i) {
		tmp[x] = 'a' + i;
		if(DFS(x + 1, len)) return true;
	}
	return false;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) {
		read(n); scanf("%s", s + 1);
		for(int i = 1; i <= 3; ++i) 
			if(DFS(1, i)) break;
	}
	return 0;
}
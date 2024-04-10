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

const int MAXN = 110;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, T;
char s[MAXN], ss[MAXN], tmp[8] = "abacaba";

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool chk(int pos) {
	int cnt = 0;
	for(int i = 1; i <= n; ++i) s[i] = ss[i]; 
	for(int i = pos; i <= pos + 6; ++i) {
		if(!(s[i] == '?' || s[i] == tmp[i - pos])) return false;
		s[i] = tmp[i - pos];
	}
	for(int i = 1; i <= n; ++i) 
		if(s[i] == '?') s[i] = 'z';
	for(int i = 1; i + 6 <= n; ++i) {
		bool flag = true;
		for(int p = i; p <= i + 6; ++p) 
			if(s[p] != tmp[p - i]) 
				flag = false;
		cnt += flag;
	}
	if(cnt == 1) return true;
	return false;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n);
		scanf("%s", ss + 1);
		bool flag = false;
		for(int i = 1; i + 6 <= n; ++i)
			if(chk(i)) {
				flag = true;
				break;
			}
		if(flag) {
			puts("Yes");
			for(int i = 1; i <= n; ++i)
				putchar(s[i]);
			putchar('\n');
		} else puts("No");
	}
	return 0;
}
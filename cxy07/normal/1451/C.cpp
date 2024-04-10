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

int T, n, m;
int bs[27], bt[27];
char s[MAXN], t[MAXN];

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
	read(T);
	while(T--) {
		int k, ans = true;
		read(n); read(k);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		for(int i = 0; i < 26; ++i) bs[i] = bt[i] = 0;
		for(int i = 1; i <= n; ++i) bs[s[i] - 'a']++;
		for(int i = 1; i <= n; ++i) bt[t[i] - 'a']++;
		for(int i = 0; i < 26; ++i) {
			if(bs[i] < bt[i]) {
				ans = false;
				break;
			}
			bs[i] -= bt[i];
			if(bs[i] % k) {
				ans = false;
				break;
			}
			if(bs[i] && i == 25) {
				ans = false;
				break;
			}
			bs[i + 1] += bs[i];
		}
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, s;
int a[MAXN], cnt[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); s = 0;
		for(int i = 1; i <= n; ++i) {
			read(a[i]);
			s ^= a[i];
		}
		if(!s) {
			puts("DRAW");
			continue;
		}
		for(int i = 0; i <= 30; ++i) cnt[i] = 0;
		for(int i = 1; i <= n; ++i) 
			for(int p = 0; p <= 30; ++p)
				if((1 << p) & a[i]) cnt[p]++;
		for(int i = 30; ~i; --i) {
			if(cnt[i] % 2 == 0) continue;
			int cnt1 = cnt[i], cnt0 = n - cnt[i];
			puts(cnt1 % 4 == 3 && cnt0 % 2 == 0 ? "LOSE" : "WIN");
			break;
		}
	}
	return 0;
}
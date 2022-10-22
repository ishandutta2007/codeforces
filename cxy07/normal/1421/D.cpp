//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 1;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T,n,m;
int x,y,ans;
int c[10];

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
		read(x); read(y);
		for(int i = 1;i <= 6; ++i) read(c[i]);
		ans = 0;
		c[6] = min(c[6],c[1] + c[5]);
		c[3] = min(c[3],c[2] + c[4]);
		c[5] = min(c[5],c[4] + c[6]);
		c[2] = min(c[2],c[1] + c[3]);
		c[1] = min(c[1],c[2] + c[6]);
		c[4] = min(c[4],c[3] + c[5]);
		if(x < 0 && y < 0) {
			ans += c[4] * min(abs(x),abs(y));
			int v = min(abs(x),abs(y));
			x += v,y += v;
		}
		if(x > 0 && y > 0) {
			ans += c[1] * (min(x,y));
			int v = min(x,y);
			x -= v,y -= v;
		}
		if(y < 0) ans += abs(y) * c[5];
		if(y > 0) ans += abs(y) * c[2];
		if(x < 0) ans += abs(x) * c[3];
		if(x > 0) ans += abs(x) * c[6];
		cout << ans << endl;
	}
	return 0;
}
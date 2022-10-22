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

const int MAXN = 1e3 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T,n,m;
int a[MAXN],now;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int gcd(int x,int y) {
	if(!y) return x;
	return gcd(y,x % y);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n);
		for(int i = 1;i <= n; ++i) read(a[i]);
		sort(a + 1,a + n + 1);
		cout << a[n] << ' ';
		now = a[n];	
		for(int i = n - 1;i >= 1; --i) {
			int pos = 1;
			for(int j = 2;j <= i; ++j) {
				if(gcd(a[j],now) > gcd(a[pos],now)) 
					pos = j;
			}
			swap(a[pos],a[i]);
			cout << a[i] << ' ';
			now = gcd(now,a[i]);
		}
		cout << endl;
	}
	return 0;
}
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

const int MAXN = 1;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, x, y;

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
	read(n); read(m); read(x); read(y);
	cout << x << ' ' << y << endl;
	int atx, aty;
	for(int i = 1; i <= n; ++i) {
		if(i == x) continue;
		cout << i << ' ' << y << endl;
		atx = i, aty = y;
	}
	for(int i = 1;i <= m; ++i) {
		if(i == y) continue;
		cout << atx << ' ' << i << endl;
		int tmp;
		for(int p = 1; p <= n; ++p) {
			if(p == atx) continue;
			tmp = p;
			cout << p << ' ' << i << endl;
		} 
		atx = tmp;
	}
	return 0;
}
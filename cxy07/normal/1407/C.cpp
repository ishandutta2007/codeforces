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

const int MAXN = 1e4 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m;
int a[MAXN];

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
	read(n);
	for(int i = 1;i <= n; ++i) {
		for(int j = 1,x,y;j <= n; ++j) {
			if(i == j || a[i] || a[j]) continue;
			printf("? %d %d\n",i,j);
			fflush(stdout);
			cin >> x;
			printf("? %d %d\n",j,i);
			cin >> y;
			if(x < y) a[j] = y;
			else a[i] = x;
		}
	}
	cout << "! ";
	for(int i = 1;i <= n; ++i)
		if(a[i]) cout << a[i] << ' ';
		else cout << n << ' ';
	cout << endl;
	return 0;
}
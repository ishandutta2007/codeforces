//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n,m,p,pi = 1;
int fa[MAXN],k;
int siz[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int find(int x) {
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int x,int y) {
	x = find(x),y = find(y);
	if(x == y) return;
	siz[x] += siz[y];
	fa[y] = x;
}

int qpow(int x,int b) {
	int res = 1;
	if(b <= 0) return res;
	for(;b;b >>= 1,(x *= x) %= p) if(b & 1) (res *= x) %= p;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m); read(p);
	for(int i = 1;i <= n; ++i) fa[i] = i,siz[i] = 1;
	for(int i = 1,x,y;i <= m; ++i) {
		read(x); read(y);
		merge(x,y);
	}
	for(int i = 1;i <= n; ++i) 
		if(fa[i] == i) (pi *= siz[i]) %= p,k++;
	if(k < 2) printf("%d\n",1 % p);
	//cout << k << endl;
	else printf("%lld\n",qpow(n,k - 2) * pi % p);
	return 0;
}
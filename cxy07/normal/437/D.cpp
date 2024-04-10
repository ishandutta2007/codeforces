//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

struct EDGE {
	int x,y,w;
	EDGE(int _x = 0,int _y = 0,int _w = 0):x(_x),y(_y),w(_w) {}
	bool operator < (const EDGE &b) const {return w > b.w;}
} e[MAXN];

int n,m,now,ans,a[MAXN];
int f[MAXN],cnt[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int find(int x) {
	if(f[x] != x) return f[x] = find(f[x]);
	return f[x];
}

int unity(int x,int y) {
	int cntx,cnty;
	x = find(x),y = find(y);
	if(x == y) return -1;
	cntx = cnt[x],cnty = cnt[y];
	cnt[x] += cnt[y];
	f[y] = x;
	return cntx * cnty;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m); 
	now = n;
	for(int i = 1;i <= n; ++i) read(a[i]);
	for(int i = 1,x,y;i <= m; ++i) {
		read(x); read(y);
		e[i] = EDGE(x,y,min(a[x],a[y]));
	}
	sort(e + 1,e + m + 1);
	for(int i = 1;i <= n; ++i) {
		f[i] = i;
		cnt[i] = 1;
	}
	for(int i = 1,x,y,w,add;i <= m; ++i) {
		x = e[i].x,y = e[i].y,w = e[i].w;
		add = unity(x,y) * w;
		if(add >= 0) {
			ans += add;
			now--;
		}
		if(now == 1) break;
	}
	ans <<= 1;
	printf("%.8lf\n",(double) ans / ((n - 1) * n));
	return 0;
}
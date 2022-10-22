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

const int MAXN = 4e5 + 10;
const int B = 18;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m;
int a[MAXN];
int fa[(1 << B) + 10],siz[(1 << B) + 10];
int buk[(1 << B) + 10];
LL ans;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int Find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

int Merge(int x,int y) {
	x = Find(x),y = Find(y);
	if(x == y) return false;
	if(siz[x] < siz[y]) swap(x,y);
	siz[x] += siz[y];
	fa[y] = x;
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 0;i < (1 << B); ++i) {
		fa[i] = i;
		siz[i] = 1;
	}
	for(int i = 1;i <= n; ++i) {
		read(a[i]);
		buk[a[i]]++;
		ans -= a[i];
	}
	buk[0]++;
	for(int w = (1 << B) - 1;~w; --w) {
		for(int x = w,y;;x = ((x - 1) & w)) {
			y = (w ^ x);
			if(buk[x] && buk[y] && Merge(x,y)) {
				ans += 1ll * (buk[x] + buk[y] - 1) * w;
				buk[x] = buk[y] = 1;
			}
			if(!x) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T,n,m,a,b,da,db,rt;
int d[MAXN];
vector<int> G[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void DFS(int x,int fa) {
	if(d[x] > d[rt]) rt = x;
	for(int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa) continue;
		d[to] = d[x] + 1;
		DFS(to,x);
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); read(a); read(b); read(da); read(db);
		for(int i = 1;i <= n; ++i) G[i].clear();
		for(int i = 1,x,y;i < n; ++i) {
			read(x); read(y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(db <= (da << 1)) {
			puts("Alice");
			continue;
		}
		d[a] = 0; rt = a;
		DFS(a,0);
		if(d[b] <= da) {
			puts("Alice");
			continue;
		}
		d[rt] = 0;
		DFS(rt,0);
		if(d[rt] <= (da << 1)) {
			puts("Alice");
			continue;
		} else {
			puts("Bob");
			continue;
		}
	}
	return 0;
}
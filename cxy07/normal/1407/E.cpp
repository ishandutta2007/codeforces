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

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN],edgesize;
	int fr[MAXN << 1],nxt[MAXN << 1],to[MAXN << 1],col[MAXN << 1];
	inline void addedge(int x,int y,int c) {
		nxt[++edgesize] = head[x];
		fr[edgesize] = x;
		to[edgesize] = y;
		col[edgesize] = c;
		head[x] = edgesize;
	}
} e,dag,rev;

int n,m;
int dis[MAXN],col[MAXN];
bool vis[MAXN];
queue<int> Q;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void BFS() {
	memset(dis,-1,sizeof dis);
	Q.push(n);
	dis[n] = 0;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		if(x == 1) break;
		for(int i = e.head[x],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(vis[to]) continue;
			if(col[to] != e.col[i]) col[to] = !e.col[i];
			else {
				if(vis[to]) continue;
				vis[to] = true;
				dis[to] = dis[x] + 1;
				Q.push(to);
			}
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	for(int i = 1,x,y,w;i <= m; ++i) {
		read(x); read(y); read(w);
		e.addedge(y,x,w);
	}
	memset(col,-1,sizeof col);
	BFS();
	cout << dis[1] << endl;
	for(int i = 1;i <= n; ++i)
		if(col[i] == -1) cout << 0;
		else cout << col[i];
	cout << endl;
	return 0;
}
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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int x,y,id;
	NODE(int _x = 0,int _y = 0,int _id = 0) : x(_x),y(_y),id(_id) {}
} a[MAXN];

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1],w[MAXN << 1];
	inline void addedge(int x,int y,int _w) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		w[edgesize] = _w;
		head[x] = edgesize;
	}
} e;

struct DijNODE {
	int id,w;
	bool operator < (const DijNODE &b) const {return w > b.w;}
	DijNODE(int _id = 0,int _w = 0) : id(_id),w(_w) {}
};

int n,m,s[2],t[2];
int dis[MAXN];
priority_queue<DijNODE> Q;
bool vis[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

bool cmpx(NODE a,NODE b) {return a.x < b.x;}
bool cmpy(NODE a,NODE b) {return a.y < b.y;}

void Dijkstra() {
	memset(dis,0x3f,sizeof dis);
	dis[m + 1] = 0;
	Q.push(DijNODE(m + 1,dis[m + 1]));
	while(Q.size()) {
		int x = Q.top().id; Q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = e.head[x],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(dis[to] > dis[x] + e.w[i]) {
				dis[to] = dis[x] + e.w[i];
				Q.push(DijNODE(to,dis[to]));
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
	read(s[0]); read(s[1]);
	read(t[0]); read(t[1]);
	for(int i = 1;i <= m; ++i) {
		read(a[i].x); read(a[i].y);
		a[i].id = i;
	}
	sort(a + 1,a + m + 1,cmpx);
	for(int i = 2;i <= m; ++i) {
		e.addedge(a[i - 1].id,a[i].id,abs(a[i - 1].x - a[i].x));
		e.addedge(a[i].id,a[i - 1].id,abs(a[i - 1].x - a[i].x));
	}
	sort(a + 1,a + m + 1,cmpy);
	for(int i = 2;i <= m; ++i) {
		e.addedge(a[i - 1].id,a[i].id,abs(a[i - 1].y - a[i].y));
		e.addedge(a[i].id,a[i - 1].id,abs(a[i - 1].y - a[i].y));
	}
	for(int i = 1;i <= m; ++i) {
		e.addedge(m + 1,a[i].id,min(abs(a[i].x - s[0]),abs(a[i].y - s[1])));
		e.addedge(a[i].id,m + 1,abs(a[i].x - s[0]) + abs(a[i].y - s[1]));
		e.addedge(m + 2,a[i].id,min(abs(a[i].x - t[0]),abs(a[i].y - t[1])));
		e.addedge(a[i].id,m + 2,abs(a[i].x - t[0]) + abs(a[i].y - t[1]));
	}
	e.addedge(m + 1,m + 2,abs(s[0] - t[0]) + abs(s[1] - t[1]));
	e.addedge(m + 2,m + 1,abs(s[0] - t[0]) + abs(s[1] - t[1]));
	Dijkstra();
	printf("%lld\n",dis[m + 2]);
	return 0;
}
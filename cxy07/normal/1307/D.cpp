//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 1e9;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1];
	inline void addedge(int x,int y) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		head[x] = edgesize;
	}
} e;

struct NODE {
	int x,y;
	bool operator < (const NODE &b) const {return (x - y) < (b.x - b.y);}
	NODE(int _x = 0,int _y = 0):x(_x),y(_y) {}
} s[MAXN];

int n,m,k,ans = 0;
int a[MAXN],maxy[MAXN];
int dis1[MAXN],dis2[MAXN];
queue<int> Q;

inline void BFS1() {
	Q.push(1);
	dis1[1] = 0;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(register int i = e.head[x],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(dis1[to] != INF) continue;
			dis1[to] = dis1[x] + 1;
			Q.push(to);
		}
	}
}

inline void BFS2() {
	Q.push(n);
	dis2[n] = 0;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(register int i = e.head[x],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(dis2[to] != INF) continue;
			dis2[to] = dis2[x] + 1;
			Q.push(to);
		}
	}
}

int main () {
	cin >> n >> m >> k;
	for(register int i = 1;i <= k; ++i)
		cin >> a[i];
	for(register int i = 1,x,y;i <= m; ++i) {
		cin >> x >> y;
		e.addedge(x,y);
		e.addedge(y,x);
	}
	for(register int i = 1;i <= n; ++i)
		dis1[i] = dis2[i] = INF;
	BFS1(),BFS2();
	for(register int i = 1;i <= k; ++i)
		s[i] = NODE(dis1[a[i]],dis2[a[i]]);
	sort(s + 1,s + k + 1);
	for(register int i = 1,x = -INF;i <= k; ++i) {
		ans = max(ans,x + s[i].y);
		x = max(x,s[i].x);
	}
	cout << min(ans + 1,dis1[n]) << endl;
	return 0;
}
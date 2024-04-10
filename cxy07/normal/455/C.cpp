#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10; 

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1],w[MAXN << 1];
	inline void addedge(int _x,int _y,int _w = 0) {
		nxt[++edgesize] = head[_x];
		to[edgesize] = _y;
		w[edgesize] = _w;
		head[_x] = edgesize;
	}
	inline void clear() {
		memset(head,0,sizeof head);
		edgesize = 0;
	}
} e;

int n,m,q,tmp,len;
int f[MAXN],dis[MAXN];

int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

inline void unity(int x,int y) {
	if(find(x) != find(y))
		f[find(x)] = find(y);
}

void DFS1(int x,int fa,int val) {
	if(val >= len) {
		len = val;
		tmp = x;
	}
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(to == fa) continue;
		DFS1(to,x,val + 1);
	}
}

void DFS2(int x,int fa,int val) {
	if(val >= len) len = val;
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(to == fa) continue;
		DFS2(to,x,val + 1);
	}
}

int main () {
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	for(register int i = 1;i <= n; ++i)
		f[i] = i;
	for(register int i = 1,x,y; i <= m; ++i) {
		scanf("%d%d",&x,&y);
		e.addedge(x,y);
		e.addedge(y,x);
		unity(x,y);
	}
	for(register int i = 1;i <= n; ++i) {
		if(dis[find(i)]) continue;
		len = 0;
		DFS1(i,0,0);
		len = 0;
		DFS2(tmp,0,0);
		dis[find(i)] = len;
	}
	while(q--) {
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt == 2) {
			scanf("%d",&y);
			if(find(x) == find(y)) continue;
			int tmp = ceil((double)(dis[find(x)] / 2.0)) + ceil((double)(dis[find(y)] / 2.0));
			int sav1 = dis[find(x)],sav2 = dis[find(y)];
			unity(x,y);
			dis[find(x)] = max(tmp + 1,max(sav1,sav2));
		} else printf("%d\n",dis[find(x)]);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int INF = 1e8 + 10;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1],w[MAXN << 1];
	
	inline void clear() {
		memset(head,0,sizeof head);
		memset(nxt,0,sizeof nxt);
		memset(to,0,sizeof to);
		memset(w,0,sizeof w);
		edgesize = 1;
	}
	
	inline void addedge(int _x,int _y,int _w) {
		nxt[++edgesize] = head[_x];
		to[edgesize] = _y;
		w[edgesize] = _w;
		head[_x] = edgesize;
	}
} e;


int n,k,ans;
int q[MAXN];
int maxsize[MAXN],root,siz[MAXN];
int totsiz,dis[MAXN],sav[MAXN];
bool vis[MAXN];

void Getroot(int x,int fa) {
	siz[x] = 1; maxsize[x] = 0;
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(vis[to] || to == fa) continue;
		Getroot(to,x);
		siz[x] += siz[to];
		maxsize[x] = max(maxsize[x],siz[to]);
	}
	maxsize[x] = max(maxsize[x],totsiz - siz[x]);
	if(maxsize[x] < maxsize[root]) root = x;
}

void Getdis(int x,int fa) {
	sav[++sav[0]] = dis[x];
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(vis[to] || to == fa) continue;
		dis[to] = dis[x] + e.w[i];
		Getdis(to,x);
	}
}

int calc(int x,int val) {
	sav[0] = 0;
	dis[x] = val;
	Getdis(x,0);
	int res = 0,L = 1,R = sav[0];
	sort(sav + L,sav + R + 1);
	while(L < R) {
		if(sav[L] + sav[R] <= k) res += R - L,L++;
		else R--;
	}
	L = 1,R = sav[0];
	while(L < R) {
		if(sav[L] + sav[R] < k) res -= R - L,L++;
		else R--;
	}
	return res;
}

void Divide(int x) {
	ans += calc(x,0);
	vis[x] = true;
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(vis[to]) continue;
		ans -= calc(to,e.w[i]);
		totsiz = siz[to];
		maxsize[root = 0] = INF;
		Getroot(to,0);
		Divide(root);
	}
}

signed main () {
	scanf("%I64d%I64d",&n,&k);
	for(register int i = 1,a,b;i < n; ++i) {
		scanf("%I64d%I64d",&a,&b);
		e.addedge(a,b,1);
		e.addedge(b,a,1);
	}
	maxsize[root] = totsiz = n;
	Getroot(1,0);
	Divide(root);
	printf("%I64d\n",ans);
	return 0;
}
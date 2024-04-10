#include<bits/stdc++.h>
using namespace std;

#define scan(e,x,i) for(register int i = e.head[x];i;i = e.nxt[i])
#define to(e,i) e.to[i]

const int MAXN = 2e5 + 10;

struct EDGE {
	int head[MAXN];
	int nxt[MAXN << 1],to[MAXN << 1];
	int edgesize;
	inline void addedge(int x,int y) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		head[x] = edgesize;
	}
} e;

int n,q,rt;
int fa[MAXN],ww[MAXN];
int siz[MAXN],son[MAXN],dep[MAXN];
int top[MAXN],w[MAXN],id[MAXN],idx;
int seg[MAXN << 2],tag[MAXN << 2];
char opt[10];

void DFS1(int x) {
	siz[x] = 1;
	dep[x] = dep[fa[x]] + 1;
	int maxson = -1;
	scan(e,x,i) {
		int y = to(e,i);
		if(y == fa[x]) continue;
		assert(fa[y] == x);//DEBUG
		DFS1(y);
		siz[x] += siz[y];
		if(maxson < siz[y]) son[x] = y,maxson = siz[y];
	}
	//cout << dp[1][1] << dp[2][1] << endl;
}

void DFS2(int x,int topf) {
	id[x] = ++idx;
	top[x] = topf;
	w[idx] = ww[x];
	if(!son[x]) return;
	DFS2(son[x],topf);
	scan(e,x,i) {
		int y = to(e,i);
		if(y == fa[x] || y == son[x]) continue;
		DFS2(y,y);
	}
}

inline void pushup(int x) {seg[x] = seg[x << 1] + seg[x << 1 | 1];}

inline void pushdown(int x,int l,int r) {
	if(tag[x]) {
		int mid = (l + r) >> 1;
		tag[x << 1] ^= 1;
		tag[x << 1 | 1] ^= 1;
		seg[x << 1] = (mid - l + 1) - seg[x << 1];
		seg[x << 1 | 1] = (r - mid) - seg[x << 1 | 1];
		tag[x] = 0;
	}
}

void build(int root,int l,int r) {
	if(l == r) {
		seg[root] = w[l];
		tag[root] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	pushup(root);
}

void update(int root,int l,int r,int L,int R) {
	if(L <= l && r <= R) {
		tag[root] ^= 1;
		seg[root] = (r - l + 1) - seg[root];
		return;
	}
	pushdown(root,l,r);
	int mid = (l + r) >> 1;
	if(L <= mid) update(root << 1,l,mid,L,R);
	if(R > mid) update(root << 1 | 1,mid + 1,r,L,R);
	pushup(root);
}

int query(int root,int l,int r,int L,int R) {
	//cout << l << r << endl;
	if(L <= l && r <= R) return seg[root];
	pushdown(root,l,r);
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid) res += query(root << 1,l,mid,L,R);
	if(R > mid) res += query(root << 1 | 1,mid + 1,r,L,R);
	return res;
}

inline void updateson(int x) {
	update(1,1,n,id[x],id[x] + siz[x] - 1);
	return;
}

inline int queryson(int x) {return query(1,1,n,id[x],id[x] + siz[x] - 1);}

int main () {
	scanf("%d",&n);
	for(register int i = 2;i <= n; ++i) {
		scanf("%d",&fa[i]);
		e.addedge(fa[i],i);
		e.addedge(i,fa[i]);
	}
	for(register int i = 1;i <= n; ++i)
		scanf("%d",&ww[i]);
	DFS1(1);
	//puts("!");
	DFS2(1,1);
	//puts("!");
	build(1,1,n);
	//puts("!");
	scanf("%d",&q);
	while(q--) {
		scanf("%s%d",opt + 1,&rt);
		if(opt[1] == 'g') printf("%d\n",queryson(rt));
		else updateson(rt);
	}
	return 0;
}
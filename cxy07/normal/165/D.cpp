#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN],to[MAXN];
	inline void addedge(int x,int y) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		head[x] = edgesize;
	}
} e;

int n,q;
int savx[MAXN],savy[MAXN];
int siz[MAXN],fa[MAXN],son[MAXN],dep[MAXN];
int id[MAXN],idx,top[MAXN],w[MAXN];
int sum[MAXN << 2],mn[MAXN << 2];

void DFS1(int x,int f) {
	fa[x] = f; dep[x] = dep[f] + 1;
	siz[x] = 1;
	int maxson = -1;
	for(register int i = e.head[x],y;i;i = e.nxt[i]) {
		y = e.to[i];
		if(y == f) continue;
		DFS1(y,x);
		siz[x] += siz[y];
		if(siz[y] > maxson) {
			maxson = siz[y];
			son[x] = y;
		}
	}
}

void DFS2(int x,int topf) {
	id[x] = ++idx;
	top[x] = topf;
	if(x != 1) w[x] = 1;
	if(!son[x]) return;
	DFS2(son[x],topf);
	for(register int i = e.head[x],y;i;i = e.nxt[i]) {
		y = e.to[i];
		if(y == fa[x] || y == son[x]) continue;
		DFS2(y,y);
	}
}

void build(int root,int l,int r) {
	if(l == r) {
		sum[root] = mn[root] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
	mn[root] = 1;
}

void update(int root,int l,int r,int pos,int val) {
	if(l == r && l == pos) {
		sum[root] = val;
		mn[root] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(root << 1,l,mid,pos,val);
	else update(root << 1 | 1,mid + 1,r,pos,val);
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
	mn[root] = min(mn[root << 1],mn[root << 1 | 1]);
}

int query(int root,int l,int r,int L,int R) {
	if(L <= l && r <= R) {
		if(mn[root] < 0) return -1;
		return sum[root];
	}
	int mid = (l + r) >> 1,tmp,res = 0;
	if(L <= mid) {
		tmp = query(root << 1,l,mid,L,R);
		if(tmp < 0) return -1;
		res += tmp;
	}
	if(R > mid) {
		tmp = query(root << 1 | 1,mid + 1,r,L,R);
		if(tmp < 0) return -1;
		res += tmp;
	}
	return res;
}

int QUERY(int x,int y) {
	int res = 0,tmp;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		tmp = query(1,1,n,id[top[x]],id[x]);
		if(tmp < 0) return -1;
		res += tmp;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	tmp = query(1,1,n,id[x] + 1,id[y]);
	if(tmp < 0) return -1;
	res += tmp;
	return res;
}

int main () {
	scanf("%d",&n);
	for(register int i = 1,x,y;i < n; ++i) {
		scanf("%d%d",&x,&y);
		e.addedge(x,y);
		e.addedge(y,x);
		savx[i] = x; savy[i] = y;
	}
	DFS1(1,0);
	DFS2(1,1);
	build(1,1,n);
	for(register int i = 1;i < n; ++i) 
		if(dep[savx[i]] < dep[savy[i]])
			swap(savx[i],savy[i]);
	scanf("%d",&q);
	while(q--) {
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt == 1) update(1,1,n,id[savx[x]],1);
		if(opt == 2) update(1,1,n,id[savx[x]],-1);
		if(opt == 3) {
			scanf("%d",&y);
			printf("%d\n",QUERY(x,y));
		}
	}
	return 0;
}
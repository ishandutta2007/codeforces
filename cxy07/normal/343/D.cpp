#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int n,Q;
int fa[MAXN],siz[MAXN],dep[MAXN],son[MAXN];
int top[MAXN],id[MAXN],dfn;
int seg[MAXN << 2],tag[MAXN << 2];
vector<int> G[MAXN];

void DFS1(int x,int f) {
	fa[x] = f;
	dep[x] = dep[f] + 1;
	siz[x] = 1;
	int maxson = -1,len = G[x].size();
	for(register int i = 0,to;i < len; ++i) {
		to = G[x][i];
		if(to == f) continue;
		DFS1(to,x);
		siz[x] += siz[to];
		if(siz[to] >= maxson) {
			maxson = siz[to];
			son[x] = to;
		}
	}
}

void DFS2(int x,int topf) {
	id[x] = ++dfn;
	top[x] = topf;
	if(son[x]) DFS2(son[x],topf);
	int len = G[x].size();
	for(register int i = 0,to;i < len; ++i) {
		to = G[x][i];
		if(to == son[x] || to == fa[x]) continue;
		DFS2(to,to);
	} 
}

void pushdown(int root) {
	if(tag[root]) {
		if(tag[root] == -1) {
			tag[root << 1] = tag[root << 1 | 1] = tag[root];
			seg[root << 1] = seg[root << 1 | 1] = 0;
		} else {
			tag[root << 1] = tag[root << 1 | 1] = tag[root];
			seg[root << 1] = seg[root << 1 | 1] = 1;
		}
		tag[root] = 0;
	}
}

void update(int root,int l,int r,int L,int R,int val) {
	if(L <= l && r <= R) {
		tag[root] = (val == 0 ? -1 : 1);
		seg[root] = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(root);
	if(L <= mid) update(root << 1,l,mid,L,R,val);
	if(R > mid) update(root << 1 | 1,mid + 1,r,L,R,val);
}

int query(int root,int l,int r,int pos) {
	if(l == r && l == pos) return seg[root];
	int mid = (l + r) >> 1;
	pushdown(root);
	if(pos <= mid) return query(root << 1,l,mid,pos);
	else return query(root << 1 | 1,mid + 1,r,pos);
}

void updateson(int x) {
	update(1,1,n,id[x],id[x] + siz[x] - 1,1);
	return;
}

void updatelink(int x) {
	int y = 1;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		update(1,1,n,id[top[x]],id[x],0);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	update(1,1,n,id[x],id[y],0);
}

int main () {
	scanf("%d",&n);
	for(register int i = 1,x,y;i < n; ++i) {
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS1(1,0);
	DFS2(1,1);
	scanf("%d",&Q);
	while(Q--) {
		int opt,pos;
		scanf("%d%d",&opt,&pos);
		if(opt == 1) updateson(pos);
		if(opt == 2) updatelink(pos);
		if(opt == 3) printf("%d\n",query(1,1,n,id[pos]));
	}
	return 0;
}
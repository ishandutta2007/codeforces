//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;

struct EDGE {
	int nxt;
	int to;
} edge[MAXN << 1];

int n,R = 1e5,cnt;
int w[MAXN];
int head[MAXN],edgesize;
int root[MAXN];
int ls[MAXN * 50],rs[MAXN * 50],sum[MAXN * 50],ans[MAXN * 50];
int sav[MAXN];

inline void addedge(int x,int y) {
	edge[++edgesize].nxt = head[x];
	edge[edgesize].to = y;
	head[x] = edgesize;
}

void pushup(int x) {
	if(sum[ls[x]] > sum[rs[x]]) {
		sum[x] = sum[ls[x]];
		ans[x] = ans[ls[x]];
	} else if(sum[ls[x]] < sum[rs[x]]) {
		sum[x] = sum[rs[x]];
		ans[x] = ans[rs[x]];
	} else {
		sum[x] = sum[ls[x]];
		ans[x] = ans[ls[x]] + ans[rs[x]];
	}
}

void update(int &root,int l,int r,int pos,int val) {
	if(!root) root = ++cnt;
	if(l == r && l == pos) {
		sum[root] += val;
		ans[root] = l;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(ls[root],l,mid,pos,val);
	else update(rs[root],mid + 1,r,pos,val);
	pushup(root);
}

int merge(int a,int b,int l,int r) {
	if(!a) return b;
	if(!b) return a;
	if(l == r) {
		sum[a] += sum[b];
		ans[a] = l;
		return a;
	}
	int mid = (l + r) >> 1;
	ls[a] = merge(ls[a],ls[b],l,mid);
	rs[a] = merge(rs[a],rs[b],mid + 1,r);
	pushup(a);
	return a;
}

void DFS(int x,int fa) {
	for(register int i = head[x],to;i;i = edge[i].nxt) {
		to = edge[i].to;
		if(to == fa) continue;
		DFS(to,x);
		merge(root[x],root[to],1,R);
	}
	update(root[x],1,R,w[x],1);
	sav[x] = ans[root[x]];
}

signed main() {
	cin >> n;
	for(register int i = 1;i <= n; ++i) {
		cin >> w[i];
		root[i] = ++cnt;
	}
	for(register int i = 1,x,y;i < n; ++i) {
		cin >> x >> y;
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1,0);
	for(register int i = 1;i <= n; ++i)
		cout << sav[i] << ' ';
	cout << endl;
	return 0;
}
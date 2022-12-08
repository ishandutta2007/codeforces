#include<bits/stdc++.h>
#define N 300000
#define zrt k << 1
#define yrt k << 1 | 1
using namespace std;
int n,m,a[N + 5];
struct node {
	int ans,za,ya,zl,yl,len;
	long long z,y,tag;
};
struct Seg {
	node s[N * 4 + 5];
	node upd(node x,node y) {
		node k;
		k.len = x.len + y.len;
		k.z = x.z;
		k.y = y.y;
		k.zl = x.zl;
		if (x.zl == x.len && x.y > y.z)
			k.zl += y.zl;
		k.yl = y.yl;
		if (y.yl == y.len && x.y < y.z)
			k.yl += x.yl;
		k.za = x.za;
		if (k.za == x.len && x.y > y.z)
			k.za += y.zl;
		if (x.yl == x.len && x.y < y.z)
			k.za = max(k.za,x.yl + y.za);
		k.ya = y.ya;
		if (k.ya == y.len && x.y < y.z)
			k.ya += x.yl;
		if (y.zl == y.len && x.y > y.z)
			k.ya = max(k.ya,y.zl + x.ya);
		k.ans = max(x.ans,y.ans);
		if (x.y > y.z)
			k.ans = max(k.ans,x.ya + y.zl);
		if (x.y < y.z)
			k.ans = max(k.ans,y.za + x.yl);
		return k;
	}
	void build(int k,int l,int r) {
		if (l == r) {
			s[k].ans = 1; s[k].ya = 1; s[k].za = 1; s[k].zl = 1; s[k].yl = 1;
			s[k].z = (long long)a[l]; s[k].y = (long long)a[l]; s[k].len = 1;
			return;
		}
		int mid = l + r >> 1;
		build(zrt,l,mid);
		build(yrt,mid + 1,r);
		s[k] = upd(s[zrt],s[yrt]);
	}
	void jia(int k,int l,int r,long long z) {
		s[k].z += z;
		s[k].y += z;
		s[k].tag += z;
	}
	void pushdown(int k,int l,int r,int mid) {
		if (!s[k].tag)
			return;
		jia(zrt,l,mid,s[k].tag);
		jia(yrt,mid + 1,r,s[k].tag);
		s[k].tag = 0;
	}
	void add(int k,int l,int r,int x,int y,long long z) {
		if (l >= x && r <= y) {
			jia(k,l,r,z);
			return;
		}
		int mid = l + r >> 1;
		pushdown(k,l,r,mid);
		if (x > mid)
			add(yrt,mid + 1,r,x,y,z);
		else if (y <= mid)
			add(zrt,l,mid,x,y,z);
		else
			add(zrt,l,mid,x,y,z),add(yrt,mid + 1,r,x,y,z);
		s[k] = upd(s[zrt],s[yrt]);
	}
} tree;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	tree.build(1,1,n);
	scanf("%d",&m);
	int l,r;
	long long z;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld",&l,&r,&z);
		tree.add(1,1,n,l,r,z);
		printf("%d\n",tree.s[1].ans);
	}
	return 0;
}
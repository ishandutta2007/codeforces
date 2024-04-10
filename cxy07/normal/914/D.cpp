#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int n,q,cnt;
int a[MAXN];
int seg[MAXN << 2];

int gcd(int x,int y) {return (y ? gcd(y,x % y) : x);}

void pushup(int x) {seg[x] = gcd(seg[x << 1],seg[x << 1 | 1]);}

void build(int root,int l,int r) {
	if(l == r) {
		seg[root] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	pushup(root);
}

void update(int root,int l,int r,int pos,int val) {
	if(l == r && l == pos) {
		seg[root] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(root << 1,l,mid,pos,val);
	else update(root << 1 | 1,mid + 1,r,pos,val);
	pushup(root);
}

void query(int root,int l,int r,int L,int R,int val) {
	if(cnt > 1) return;
	if(l == r) return (void)(cnt++);
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid && seg[root << 1] % val) query(root << 1,l,mid,L,R,val);
	if(R > mid && seg[root << 1 | 1] % val) query(root << 1 | 1,mid + 1,r,L,R,val);
	return;
}

int main () {
	scanf("%d",&n);
	for(register int i = 1;i <= n; ++i)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	while(q--) {
		int opt,x,y,v;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt == 1) {
			cnt = 0;
			scanf("%d",&v);
			query(1,1,n,x,y,v);
			puts((cnt > 1) ? "NO" : "YES");
		} else update(1,1,n,x,y);
	}
	return 0;
}
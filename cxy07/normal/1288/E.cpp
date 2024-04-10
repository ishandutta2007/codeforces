//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6e5 + 10;

int n,m,now;
int minp[MAXN],maxp[MAXN],pos[MAXN];
int seg[MAXN << 2];

void update(int root,int l,int r,int pos,int v) {
	if(l == r && l == pos) return (void)(seg[root] += v);
	int mid = (l + r) >> 1;
	if(pos <= mid) update(root << 1,l,mid,pos,v);
	else update(root << 1 | 1,mid + 1,r,pos,v);
	seg[root] = seg[root << 1] + seg[root << 1 | 1];
}

int query(int root,int l,int r,int L,int R) {
	if(L <= l && r <= R) return seg[root];
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid) res += query(root << 1,l,mid,L,R);
	if(R > mid) res += query(root << 1 | 1,mid + 1,r,L,R);
	return res;
}

int main () {
	scanf("%d%d",&n,&m);
	for(register int i = 1;i <= n; ++i) {
		minp[i] = maxp[i] = i;
		pos[i] = i + m;
		update(1,1,n + m,pos[i],1);
	}
	now = m + 1;
	for(register int i = 1,x;i <= m; ++i) {
		now--;
		scanf("%d",&x);
		minp[x] = 1;
		maxp[x] = max(maxp[x],query(1,1,n + m,1,pos[x]));
		update(1,1,n + m,pos[x],-1);
		pos[x] = now;
		update(1,1,n + m,pos[x],1);
	}
	for(register int i = 1;i <= n; ++i)
		maxp[i] = max(maxp[i],query(1,1,n + m,1,pos[i]));
	for(register int i = 1;i <= n; ++i)
		printf("%d %d\n",minp[i],maxp[i]);
	return 0;
}
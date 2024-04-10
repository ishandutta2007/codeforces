#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int a[maxn];
int tag[maxn*4][101];
void build(int now,int l,int r){
	for (int i=1;i<=100;++i) tag[now][i]=i;
	if (l==r) return;
	int mid=(l+r)/2;
	build(now*2,l,mid); build(now*2+1,mid+1,r);
}
inline void pushdown(int now){
	for (int i=1;i<=100;++i){
		tag[now*2][i]=tag[now][tag[now*2][i]]; tag[now*2+1][i]=tag[now][tag[now*2+1][i]];
	}
	for (int i=1;i<=100;++i) tag[now][i]=i;
}
void update(int now,int l,int r,int cl,int cr,int x,int y){
	if (r<cl||l>cr) return;
	if (l>=cl&&r<=cr){
		for (int i=1;i<=100;++i) if (tag[now][i]==x) tag[now][i]=y;
		return;
	}
	pushdown(now);
	int mid=(l+r)/2;
	update(now*2,l,mid,cl,cr,x,y); update(now*2+1,mid+1,r,cl,cr,x,y);
}
void put(int now,int l,int r){
	if (l==r){
		printf("%d ",tag[now][a[l]]); return;
	}
	pushdown(now);
	int mid=(l+r)/2;
	put(now*2,l,mid); put(now*2+1,mid+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1,l,r,x,y;i<=m;++i){
		scanf("%d%d%d%d",&l,&r,&x,&y);
		update(1,1,n,l,r,x,y);
	}
	put(1,1,n);
	return 0;
}
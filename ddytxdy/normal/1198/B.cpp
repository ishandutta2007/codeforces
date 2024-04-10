#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,q,a[N];
struct node{
	int l,r,la;
}t[N*4];
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;t[x].la=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void change1(int x,int l,int r,int d){
	if(t[x].l>=l&&t[x].r<=r){
		t[x].la=max(t[x].la,d);
		return;
	}
	if(t[x].la){
		change1(x<<1,1,n,t[x].la);
		change1(x<<1|1,1,n,t[x].la);
		t[x].la=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)change1(x<<1,l,r,d);
	if(r>mid)change1(x<<1|1,l,r,d);
}
void change2(int x,int p,int d){
	if(t[x].l==t[x].r){
		t[x].la=0;a[p]=d;
		return;
	}
	if(t[x].la){
		change1(x<<1,1,n,t[x].la);
		change1(x<<1|1,1,n,t[x].la);
		t[x].la=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)change2(x<<1,p,d);
	else change2(x<<1|1,p,d);
}
void solve(int x){
	if(t[x].l==t[x].r){
		a[t[x].l]=max(a[t[x].l],t[x].la);
		return;
	}
	t[x<<1].la=max(t[x].la,t[x<<1].la);
	t[x<<1|1].la=max(t[x].la,t[x<<1|1].la);
	solve(x<<1);solve(x<<1|1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1,k,x,y;i<=q;i++){
		scanf("%d%d",&k,&x);
		if(k==1)scanf("%d",&y),change2(1,x,y);
		else change1(1,1,n,x);
	}
	solve(1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
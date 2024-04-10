#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50,M=1e6+1;
int n,m,q,a[N],b[N];
struct node{
	int l,r,mx,laz;
}t[M*4];
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void change(int x,int l,int r,int k){
	if(t[x].r<=r){
		t[x].mx+=k,t[x].laz+=k;
		return;
	}
	if(t[x].laz){
		change(x<<1,1,M-1,t[x].laz);
		change(x<<1|1,1,M-1,t[x].laz);
		t[x].laz=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	change(x<<1,l,r,k);
	if(r>mid)change(x<<1|1,l,r,k);
	t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);
}
int ask(){
	int x=1;
	while(t[x].l!=t[x].r){
		if(t[x].laz){
			change(x<<1,1,M,t[x].laz);
			change(x<<1|1,1,M,t[x].laz);
			t[x].laz=0;
		}
		if(t[x<<1|1].mx>0)x=x<<1|1;
		else x<<=1;
	}
	if(t[x].mx>0)return t[x].l;
	return -1;
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,M-1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),change(1,1,a[i],1);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),change(1,1,b[i],-1);
	scanf("%d",&q);
	for(int i=1,k,x,y;i<=q;i++){
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)change(1,1,a[x],-1),a[x]=y,change(1,1,a[x],1);
		else change(1,1,b[x],1),b[x]=y,change(1,1,b[x],-1);
		printf("%d\n",ask());
	}
	return 0;
}
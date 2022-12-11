#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int T,n,m,a[N],l,r,q;
struct node{
	int l,r,val,ans;
}t[N*4];
node merge(node a,node b){
	node ret;
	ret.l=a.l;ret.r=b.r;
	ret.ans=a.ans+b.ans;
	if(a.val+b.val>=10)ret.ans++;
	ret.val=(a.val+b.val)%10;
	return ret;
}
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r){
		t[x].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x]=merge(t[x<<1],t[x<<1|1]);
}
//void chenge(int x,int l,int r,int d){
//	if(t[x].l>=l&&t[x].r<=r){
//		//do something
//		return;
//	}
//	if(t[x].la){
//		chenge(x<<1,1,n,t[x].la);
//		chenge(x<<1|1,1,n,t[x].la);
//		t[x].la=0;
//	}
//	int mid=(t[x].l+t[x].r)>>1;
//	if(l<=mid)chenge(x<<1,l,r,d);
//	if(r>mid)chenge(x<<1|1,l,r,d);
//	t[x]=merge(t[x<<1],t[x<<1|1]);
//}
node ask(int x,int l,int r){
	if(t[x].l>=l&&t[x].r<=r)return t[x];
//	if(t[x].la){
//		chenge(x<<1,1,n,t[x].la);
//		chenge(x<<1|1,1,n,t[x].la);
//		t[x].la=0;
//	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid&&r>mid)return merge(ask(x<<1,l,r),ask(x<<1|1,l,r));
	if(l<=mid)return ask(x<<1,l,r);
	return ask(x<<1|1,l,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		node x=ask(1,l,r);
		printf("%d\n",x.ans);
	}
	return 0;
}
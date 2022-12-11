#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=3e5+50;
int n,r,x[N],y[N],c[N*2],m,ans;
struct node{
	int x,y1,y2,k;
	bool friend operator <(node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.k>0&&b.k<0;
	}
}a[N*2];
struct node1{
	int l,r,dat,la;
}t[N*8];
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void change(int x,int l,int r,int k){//cout<<1;
	if(t[x].l>=l&&t[x].r<=r){
		t[x].dat+=k;t[x].la+=k;
		return;
	}
	if(t[x].la){
		change(x<<1,1,m,t[x].la);
		change(x<<1|1,1,m,t[x].la);
		t[x].la=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)change(x<<1,l,r,k);
	if(r>mid)change(x<<1|1,l,r,k);
	t[x].dat=max(t[x<<1].dat,t[x<<1|1].dat);
}
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		x[i]=a+b;y[i]=b-a;
		c[i]=y[i];c[i+n]=y[i]+2*r;
	}
	sort(c+1,c+2*n+1);m=unique(c+1,c+2*n+1)-c-1;
	for(int i=1;i<=n;i++){
		int ll=lower_bound(c+1,c+m+1,y[i])-c;
		int rr=lower_bound(c+1,c+m+1,y[i]+2*r)-c;
//		printf("%d %d\n",ll,rr);
		a[i]=(node){x[i],ll,rr,1};
		a[i+n]=(node){x[i]+2*r,ll,rr,-1};
	}
	build(1,1,m);
	sort(a+1,a+2*n+1);
//	for(int i=1;i<=2*n;i++)printf("%d %d\n",a[i].y1,a[i].y2);
	for(int i=1;i<=n*2;i++){
		change(1,a[i].y1,a[i].y2,a[i].k);
//		printf("%d %d %d %d\n",a[i].y1,a[i].y2,a[i].k,t[1].dat);
		ans=max(ans,t[1].dat);
	}
	printf("%d\n",ans);
	return 0;
}
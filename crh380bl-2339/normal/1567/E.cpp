#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int a[N];
struct tree{
	int lt,rt,s,len;
	long long ans;
}t[N*4];
long long C(int x){
	return 1LL*x*(x+1)>>1LL;
}
void up(int x){
	if(t[x<<1].lt<t[x<<1].len)t[x].lt=t[x<<1].lt;
	else t[x].lt=t[x<<1].lt+t[x<<1|1].lt;
	if(t[x<<1|1].rt<t[x<<1|1].len)t[x].rt=t[x<<1|1].rt;
	else t[x].rt=t[x<<1|1].rt+t[x<<1].rt;
	t[x].ans=t[x<<1].ans+t[x<<1|1].ans-C(t[x<<1].rt)-C(t[x<<1|1].lt)+C(t[x<<1].rt+t[x<<1|1].lt);
	t[x].s=t[x<<1].s+t[x<<1|1].s;
}
void init(int i,int l,int r){
	t[i].len=r-l+1;
	if(l==r){
		t[i].s=t[i].lt=t[i].rt=(a[l]>=a[l-1]);
		t[i].ans=0;
		return;
	}
	int mid=(l+r)>>1;
	init(i<<1,l,mid);
	init(i<<1|1,mid+1,r);
	up(i);
	//printf("<%d,%d>%d,%lld\n",l,r,t[i].s,t[i].ans);
}
void change(int i,int l,int r,int x,int y){
	if(l==r){
		t[i].s=t[i].lt=t[i].rt=(y>=0);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(i<<1,l,mid,x,y);
	else change(i<<1|1,mid+1,r,x,y);
	up(i);
}
ll query(int i,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[i].ans+t[i].s;
	int mid=(l+r)>>1;
	if(x<=mid&&y>mid){
		long long res=query(i<<1,l,mid,x,y)+query(i<<1|1,mid+1,r,x,y);
		int l1=min(t[i<<1].rt,mid-x+1),l2=min(t[i<<1|1].lt,y-mid);
		res=res+C(l1+l2)-C(l1)-C(l2);
		return res;
	}
	else if(x<=mid)return query(i<<1,l,mid,x,y);
	else return query(i<<1|1,mid+1,r,x,y);
}
int main(){
	int n,q,i,j,o,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	init(1,1,n);
	while(q--){
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			change(1,1,n,x,y-a[x-1]);
			if(x<n)change(1,1,n,x+1,a[x+1]-y);
			a[x]=y;
		}
		else printf("%lld\n",(x<y?query(1,1,n,x+1,y):0)+y-x+1);
	}
	return 0;
}
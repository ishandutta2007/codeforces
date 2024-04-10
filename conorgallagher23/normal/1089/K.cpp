#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+5;
int p[N],v[N],lim=1e6;LL sum[N<<2],ma[N<<2],ans;
void update(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	ma[rt]=max(ma[rt<<1]+sum[rt<<1|1],ma[rt<<1|1]);
}
void build(int rt,int l,int r){
	if(l==r){ma[rt]=l;return;}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	update(rt);
}
void change(int rt,int l,int r,int x,int y){
	if(l==r){ma[rt]+=(LL)y;sum[rt]+=(LL)y;return;}
	int mid=(l+r)>>1;
	(x<=mid)?change(rt<<1,l,mid,x,y):change(rt<<1|1,mid+1,r,x,y);
	update(rt);
}
void ask(int rt,int l,int r,int t){
	if(r<=t){ans=max(ma[rt],ans+sum[rt]);return;}
	int mid=(l+r)>>1;
	ask(rt<<1,l,mid,t);
	if(t>mid)ask(rt<<1|1,mid+1,r,t);
}
int main(){
	int T;scanf("%d",&T);
	build(1,1,lim);
	for(int i=1;i<=T;i++){
		char opt[5];scanf("%s",opt);scanf("%d",&p[i]);
		if(opt[0]=='+'){
			scanf("%d",&v[i]);
			change(1,1,lim,p[i],v[i]);
		}
		if(opt[0]=='-')change(1,1,lim,p[p[i]],-v[p[i]]);
		if(opt[0]=='?')ans=0,ask(1,1,lim,p[i]),printf("%lld\n",ans-p[i]);
	}
	return 0;
}
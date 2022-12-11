#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=1e6+50;
const LL inf=1e16;
int n,m,p;LL now,sum[N];
vector<LL>v[N*4];
int read(){
	int x=0,c,f=1;
	while(!isdigit(c=getchar()))c=='-'?f=-1:0;
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*f;
}
void up(int x,LL S){
	int L=x<<1,R=x<<1|1;
	v[x].resize(v[L].size()+v[R].size()-1,inf);
	for(int i=0,j=0;i<v[L].size();i++){
		LL xl=v[L][i],xr=i==v[L].size()-1?inf:v[L][i+1]-1,yl=xl+S-1ll*i*p,yr=xr+S-1ll*i*p;
		if(j)j--;
		while(j<v[R].size()-1&&v[R][j+1]<=yl)j++;
		for(;j<v[R].size()&&v[R][j]<=yr;j++)v[x][i+j]=min(v[x][i+j],max(xl,v[R][j]-S+1ll*i*p));
	}
	v[x][0]=-inf;
}
void build(int x,int l,int r){
	if(l==r){sum[l]=sum[l-1]+read(),v[x].pb(-inf);v[x].pb(p-(sum[l]-sum[l-1]));return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	up(x,sum[mid]-sum[l-1]);
}
void query(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){now+=sum[r]-sum[l-1]-1ll*(upper_bound(v[x].begin(),v[x].end(),now)-v[x].begin()-1)*p;return;}
	int mid=(l+r)>>1;
	if(ql<=mid)query(x<<1,l,mid,ql,qr);
	if(qr>mid)query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	n=read();m=read();p=read();
	build(1,1,n);
	for(int i=1,l,r;i<=m;i++){
		l=read();r=read();
		now=0;query(1,1,n,l,r);
		printf("%lld\n",now);
	}
	return 0;
}
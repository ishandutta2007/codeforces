#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,L[500005],R[500005],C[500005];
ll s[3][500005],w[1100000];
ll gz[500005],mx[1100000],xm[1100000];
vector<int>v[1100000];
void updw(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		w[i]=min(w[i],(ll)C[x]);
		v[i].push_back(x);
		return;
	}
	int md=(l+r)>>1;
	updw(i<<1,l,md,a,b,x),updw(i<<1|1,md+1,r,a,b,x);
}
void init(int i,int l,int r){
	if(l==r)return;
	int md=(l+r)>>1;
	w[i<<1]=min(w[i<<1],w[i]),init(i<<1,l,md);
	w[i<<1|1]=min(w[i<<1|1],w[i]),init(i<<1|1,md+1,r);
}
void pushl(int i,int l,int r,int p){
	if(l==p)
		for(auto j:v[i])
			mx[i]=max(mx[i],gz[j]-C[j]);
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)pushl(i<<1,l,md,p);
		else pushl(i<<1|1,md+1,r,p);
	}
}
void pushr(int i,int l,int r,int p,ll x){
	xm[i]=max(xm[i],x);
	if(r==p)
		for(auto j:v[i])
			gz[j]=max(gz[j],xm[i]);
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md){
			pushr(i<<1,l,md,p,x);
			mx[i<<1|1]=max(mx[i<<1|1],xm[i<<1]-w[i]);
		}else pushr(i<<1|1,md+1,r,p,x);
	}
}
ll qry(int i,int l,int r,int p){
	ll x=mx[i];
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)x=max(x,qry(i<<1,l,md,p));
		else x=max(x,qry(i<<1|1,md+1,r,p));
	}
	return x;
}
ll qryw(int i,int l,int r,int p){
	ll x=w[i];
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)x=min(x,qryw(i<<1,l,md,p));
		else x=min(x,qryw(i<<1|1,md+1,r,p));
	}
	return x;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			int x;scanf("%d",&x);
			s[i][j]=s[i][j-1]+x;
		}
	}
	for(int i=0;i<1100000;i++)w[i]=1e18,xm[i]=mx[i]=-1e18;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&L[i],&R[i],&C[i]);
		updw(1,1,n,L[i],R[i],i),gz[i]=-1e18;
	}
	init(1,1,n);
	ll ans=-1e18;
	for(int i=1;i<=n;i++){
		pushl(1,1,n,i);
		ll w=qry(1,1,n,i)+s[1][i];
		w=max(w,s[0][i]+s[1][i]-s[1][i-1]-qryw(1,1,n,i));
		ans=max(ans,w+s[2][n]-s[2][i-1]);
		ll t=max(w-s[1][i],s[0][i]-s[1][i-1]);
		pushr(1,1,n,i,t);
		if(i<n)pushr(1,1,n,i+1,w-s[1][i]);
	}
	printf("%lld",ans);
}
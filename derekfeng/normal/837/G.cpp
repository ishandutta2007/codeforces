#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define mkp make_pair
#define fi first
#define se second 
const int Inf=1e9;
pll operator +(const pll &A,const pll &B){
	return mkp(A.fi+B.fi,A.se+B.se);
}
int n,m;
int rt[75004],cnt;
int s[2][13500000];
pll dat[13500000];
int ins(int l,int r,int id,int a,int b,pll x){
	if(r<a||b<l)return id;
	int id1=++cnt;
	s[0][id1]=s[0][id],s[1][id1]=s[1][id],dat[id1]=dat[id];
	if(a<=l&&r<=b)dat[id1]=dat[id1]+x;
	else{
		int mid=(l+r)>>1;
		s[0][id1]=ins(l,mid,s[0][id1],a,b,x);
		s[1][id1]=ins(mid+1,r,s[1][id1],a,b,x);
	}
	return id1;
}
ll f(int l,int r,int id,int p){
	if(!id)return 0;
	ll res=dat[id].fi*p+dat[id].se;
	if(l!=r){
		int mid=(l+r)>>1;
		if(p<=mid)res+=f(l,mid,s[0][id],p);
		else res+=f(mid+1,r,s[1][id],p);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int X1,X2,Y1,A,B,Y2;scanf("%d%d%d%d%d%d",&X1,&X2,&Y1,&A,&B,&Y2);
		rt[i]=rt[i-1];
		rt[i]=ins(0,Inf-1,rt[i],0,X1,mkp(0,Y1));
		rt[i]=ins(0,Inf-1,rt[i],X1+1,X2,mkp(A,B));
		rt[i]=ins(0,Inf-1,rt[i],X2+1,Inf-1,mkp(0,Y2));
	}
	scanf("%d",&m);
	int lst=0;
	while(m--){
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		x=(x+lst)%Inf;
		ll tmp=f(0,Inf-1,rt[r],x)-f(0,Inf-1,rt[l-1],x);
		printf("%I64d\n",tmp);
		lst=tmp%Inf;
	}
}
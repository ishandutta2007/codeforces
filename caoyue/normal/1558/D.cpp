#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=4e5+7;
const int INF=1e9+7;
const ll mod=998244353;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
int T,n,m,cnt=0;
int X[N],Y[N];
struct Tree{int l,r,ls,rs,sm;}tr[N*4];
int newnode(int l,int r){
	tr[++cnt]=(Tree){l,r,0,0,0};
	return cnt;
}
int check(int p,int L,int R){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return tr[p].sm;
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)if(tr[p].ls)ans+=check(tr[p].ls,L,R);
	if(R>mid)if(tr[p].rs)ans+=check(tr[p].rs,L,R);
	return ans;
}
void upd(int p){
	tr[p].sm=0;
	if(tr[p].ls)tr[p].sm+=tr[tr[p].ls].sm;
	if(tr[p].rs)tr[p].sm+=tr[tr[p].rs].sm;
}
void ins(int p,int x){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		tr[p].sm=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		if(!tr[p].ls)tr[p].ls=newnode(l,mid);
		ins(tr[p].ls,x);
	}
	else{
		if(!tr[p].rs)tr[p].rs=newnode(mid+1,r);
		ins(tr[p].rs,x);
	}
	upd(p);
} 
int fd(int x){
	int l=0,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(mid-check(1,1,mid)>=x)r=mid;
		else l=mid;
	}
	return r;
}
ll fac[N],inv[N];
ll C(ll x,ll y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%d",&T);
	fac[0]=1;
	for(ll i=1;i<=400005;i++)fac[i]=fac[i-1]*i%mod;
	inv[400005]=Pow(fac[400005],mod-2);
	for(ll i=400005;i;i--)inv[i-1]=inv[i]*i%mod;
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,m)scanf("%d%d",&X[i],&Y[i]);
		cnt=0;
		tr[++cnt]=(Tree){1,n,0,0,0};
		int gg=n;
		for(int i=m;i;i--){
			int t1=fd(Y[i]),t2=fd(Y[i]+1);
			ins(1,t1);
			if(t1==t2-1)gg--;
		}
		printf("%lld\n",C(gg+n-1,n));
	}
	return 0; 
}
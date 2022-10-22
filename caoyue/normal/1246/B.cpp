#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e10+7;
ll a[N],p[N],fr[N],w[N];
bool is[N];
ll cnt=0,n,k;

int main(){
	scanf("%I64d%I64d",&n,&k);
	rep(i,n)scanf("%I64d",&a[i]);
	REP(i,2,100000){
		if(!is[i])p[++cnt]=i,fr[i]=i;
		rep(j,cnt){
			if(i*p[j]>100000)break;
			is[i*p[j]]=1;
			fr[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	ll ans=0;
	rep(i,n){
		ll nw=a[i],ls=fr[a[i]],g=1,h=1;
		while(nw>1){
			ll s=0;
			while(fr[nw]==ls){
				nw/=fr[nw];
				s++;
			}
			rep(j,s%k)h*=ls;
			s=(1000*k-s)%k;
			rep(j,s){
				if(g>N)break;
				g*=ls;
			}
			ls=fr[nw];
		}
		if(g<N)ans+=w[g];
		w[h]++;
	}
	printf("%I64d\n",ans);
	return 0;
}
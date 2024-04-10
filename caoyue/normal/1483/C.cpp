#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=3e5+7;
const ll INF=1e9+7;
ll n;
ll h[N],b[N],f[N],st[N],sv[N];
struct pir{
	ll x,v;
	friend bool operator < (pir a,pir b){
		if(a.v!=b.v)return a.v>b.v;
		return a.x<b.x;
	}
};
set<pir>S;
ll hf[22][N],mn[N*2];
void ins(ll x){
	hf[0][x]=f[x];
	for(ll i=1;x-(1<<i)+1>=0;i++){
		ll t=x-(1<<i)+1;
		hf[i][t]=max(hf[i-1][t],hf[i-1][t+(1<<(i-1))]);
	}
}
ll check(ll L,ll R){
	ll k=mn[R-L+1];
	return max(hf[k][L],hf[k][R-(1<<k)+1]);
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&h[i]);
	rep(i,n)scanf("%lld",&b[i]);
	f[0]=0;
	for(ll i=1;(1<<i)<=n+1;i++)REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	ins(0);
	ll tp=0;
	st[0]=0;
	rep(i,n){
		while(tp&&h[st[tp]]>h[i]){
			S.erase((pir){st[tp],sv[tp]});
			tp--;
		}
		sv[tp+1]=check(st[tp],i-1)+b[i];
		S.insert((pir){i,sv[tp+1]});
		st[++tp]=i;
		f[i]=(*S.begin()).v;
		ins(i);
	}
	printf("%lld\n",f[n]);
	return 0;
}
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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll M=1e6+7;
const ll INF=1e9+7;
ll n,cnt=0,tot=0;
ll mx[N],mn[N],v[N],t[M];
int main(){
	scanf("%I64d",&n);
	rep(i,n){
		ll l,fl=0; scanf("%I64d",&l);
		mx[i]=-INF;
		mn[i]=INF;
		rep(j,l){
			ll x; scanf("%I64d",&x);
			if(x>mn[i])fl=1;
			mn[i]=min(mn[i],x);
			mx[i]=max(mx[i],x);
		}
		if(fl)cnt++;
		else v[++tot]=i;
	}
	memset(t,0,sizeof(t));
	ll ans=cnt*cnt+cnt*tot*2;
	rep(i,tot)t[mn[v[i]]]++;
	rep(i,M-1)t[i]+=t[i-1];
	rep(i,tot)ans+=t[mx[v[i]]-1];
	printf("%I64d\n",ans);
	return 0;
}
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
const ll N=2e5+7;
const ll INF=1e9+7;
ll n;
ll p[N],s[N],g[N],c[N],d[N],dg[N];
int main(){
	scanf("%I64d",&n);
	REP(i,2,n)scanf("%I64d",&p[i]);
	rep(i,n){
		scanf("%I64d",&s[i]);
		c[i]=c[p[i]]+1;
		g[i]=d[i]=s[i];
		if(s[i]<0)g[i]=INF;
		if(s[i]<0&&c[i]&1){puts("-1"); return 0;}
		if(d[i]<0)d[i]=d[p[i]];
		if(d[p[i]]>d[i]){puts("-1"); return 0;}
	}
	for(int i=n;i;i--){
		if(g[i]==INF)g[i]=g[p[i]];
		if(s[p[i]]<0)g[p[i]]=min(g[p[i]],g[i]);
	}
	ll ans=0;
	rep(i,n)ans+=g[i]-g[p[i]];
	printf("%I64d\n",ans);
	return 0;
}
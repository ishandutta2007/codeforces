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
const ll N=5e5+7;
const ll INF=1e18+7;
char s[N];
ll f[N];
ll n,p,k;

int main(){
	ll T; scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d",&n,&p,&k);
		scanf("%s",s+1);
		ll x,y,ans=INF; scanf("%I64d%I64d",&x,&y);
		for(ll i=n;i;i--){
			if(i+k<=n)f[i]=f[i+k];
			else f[i]=0;
			if(s[i]=='0')f[i]+=x;
			if(i>=p)ans=min(ans,f[i]+(i-p)*y);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
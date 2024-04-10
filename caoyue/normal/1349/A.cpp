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
const ll N=2e5+7;
const ll INF=1e9+7;
ll n,mx=0;
ll a[N],mi[N],cm[N],ss[N];

int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)mx=max(mx,a[i]);
	rep(i,mx)mi[i]=cm[i]=INF,ss[i]=0;
	rep(i,n){
		REP(j,2,sqrt(a[i])){
			if(a[i]%j==0){
				ll s=0;
				while(a[i]%j==0)a[i]/=j,s++;
				ss[j]++;
				if(s<mi[j])cm[j]=mi[j],mi[j]=s;
				else if(s<cm[j])cm[j]=s;
			}
		}
		if(a[i]>1){
			ss[a[i]]++;
			if(mi[a[i]]>1)mi[a[i]]=1;
			else if(cm[a[i]]>1)cm[a[i]]=1;
		}
	}
	ll ans=1;
	REP(i,2,mx){
		if(ss[i]<=n-2)continue;
		if(ss[i]==n-1){
			rep(j,mi[i])ans=ans*i;
		}
		else rep(j,cm[i])ans=ans*i;
	}
	printf("%lld\n",ans);
	return 0;
}
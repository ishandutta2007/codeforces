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
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll s[N],f[N];
ll m,iv;
vector<ll>p[N];

int main(){
	scanf("%I64d",&m);
	iv=Pow(m,mod-2); 
	f[1]=0;
	rep(i,m)for(ll j=i;j<=m;j+=i)p[j].push_back(i);
	REP(i,2,m){
		ll hh=m;
		for(ll j=p[i].size()-1;~j;j--){
			s[j]=m/p[i][j];
			for(ll k=p[i].size()-1;k>j;k--)if(p[i][k]%p[i][j]==0)s[j]-=s[k];
			if(j!=p[i].size()-1)hh=(hh+s[j]*f[p[i][j]])%mod;
		}
		f[i]=hh*Pow((1-s[p[i].size()-1]*iv%mod+mod),mod-2)%mod*iv%mod;
	}
	ll ans=0;
	rep(i,m)ans=(ans+f[i])%mod;
	printf("%I64d\n",(ans*iv+1)%mod);
	return 0;
}
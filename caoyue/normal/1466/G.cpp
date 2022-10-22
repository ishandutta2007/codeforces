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
const ll N=1e6+7;
const ll mod=1e9+7;
const ll mod1=1004535809;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll n,m,q,tot;
char s[N],t[N],ss[N];
ll p2[N],ip[N],nx[N],c[N],hs[N],hh[N],p29[N],h[105][105],sv[100007][26];
void pre(){
	for(ll i=1;i<=m;i++){
		ll ls=nx[i-1];
		while(ls&&s[ls+1]!=s[i])ls=nx[ls];
		if(s[ls+1]==s[i]&&ls+1!=i)nx[i]=ls+1;
		else nx[i]=0;
	}
	hs[m+1]=hh[0]=0;
	for(ll i=m;i;i--)hs[i]=(hs[i+1]*31ll+(s[i]-'a'+1))%mod1;
	rep(i,m)hh[i]=(hh[i-1]*31ll+(s[i]-'a'+1))%mod1;
	rep(i,m){
		h[i][i-1]=0;
		REP(j,i,m)h[i][j]=(h[i][j-1]*31ll+(s[j]-'a'+1))%mod1;
	}
	p29[0]=1;
	rep(i,m)p29[i]=p29[i-1]*31ll%mod1;
}
vector<ll>E[N*2];
ll solve(ll o,ll nw,ll R){
	if(nw>R)return 0;
	if(nw==R){
		if(E[o].size()>1)return 0;
		if(E[o][0]!=t[nw]-'a')return 0;
		return 1;
	}
	if(E[o].size()==1)return (sv[nw][E[o][0]]-sv[R+1][E[o][0]]+mod)*p2[R]%mod;
	bool f0=1,f1=1;
	rep0(j,E[o].size()){
		if(E[o][j]!=t[nw]-'a'){
			if(j&1)f1=0;
			else f0=0;
		}
	}
	ll ans=0;
	if(f0){
		E[++tot].clear();
		rep0(j,E[o].size())if(j&1)E[tot].push_back(E[o][j]);
		ans=(ans+solve(tot,nw+1,R))%mod;
	}
	if(f1){
		E[++tot].clear();
		rep0(j,E[o].size())if(j%2==0)E[tot].push_back(E[o][j]);
		ans=(ans+solve(tot,nw+1,R))%mod;
	}
	return ans;
}
int main(){
	scanf("%I64d%I64d",&n,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	m=strlen(s+1);
	s[m+1]='#';
	p2[0]=1;
	rep(i,n+1)p2[i]=p2[i-1]*2%mod;
	ip[n]=Pow(p2[n],mod-2);
	for(ll i=n;i;i--)ip[i-1]=ip[i]*2%mod;
	rep0(j,26)sv[n+1][j]=0;
	for(ll i=n;i;i--)rep0(j,26)sv[i][j]=(sv[i+1][j]+(t[i]-'a'==j)*ip[i])%mod;
	pre();
	while(q--){
		ll x,o; scanf("%I64d",&x);
		scanf("%s",ss+1);
		o=strlen(ss+1);
		if(o>m){
			rep0(i,m+1)c[i]=1;
			ll nw=0;
			rep(i,o){
				while(s[nw+1]!=ss[i]&&nw)nw=nx[nw];
				if(s[nw+1]==ss[i])nw++;
				if(nw!=m&&i>=m)c[i%(m+1)]=0;
			}
			ll sm=0;
			rep(i,m){
				sm=(sm+p29[i-1]*((ll)(ss[i]-'a'+1)))%mod1;
				if(sm!=hs[m-i+1])c[i]=0;
			}
			sm=0;
			rep0(i,m){
				sm=(sm+p29[i]*((ll)(ss[o-i]-'a'+1)))%mod1;
				if(sm!=hh[i+1])c[(o-i+m-1)%(m+1)]=0;
			}
		}
		else{
			rep0(i,m+1)c[i]=1;
			ll sm=0;
			rep(i,o){
				sm=(sm+p29[i-1]*(ll)(ss[i]-'a'+1))%mod1;
				if(sm!=hs[m-i+1])c[i]=0;
			}
			sm=0;
			rep0(i,o){
				sm=(sm+p29[i]*(ll)(ss[o-i]-'a'+1))%mod1;
				if(sm!=hh[i+1])c[(o-i-2+m+1)%(m+1)]=0;
			}
			for(ll i=1;i+o-1<=m;i++)if(sm!=h[i][i+o-1])c[(m-i+1+(m+1))%(m+1)]=0;
		}
		ll ans=0;
		rep0(i,m+1){
			if(c[i]){
				tot=0;
				E[0].clear();
				for(ll j=i+1;j<=o;j+=(m+1))E[0].push_back(ss[j]-'a');
				if(!E[0].size()){
					ans=(ans+p2[x])%mod;
					continue;
				}
				ans=(ans+solve(0,1,x))%mod;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
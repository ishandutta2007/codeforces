#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e3+7;
const ll mod=1e9+7;
ll f[N][N];
ll k,a,b,p=0;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	scanf("%I64d%I64d%I64d",&k,&a,&b);
	ll t=Pow(a+b,mod-2);
	a=a*t%mod;
	b=b*t%mod;
	f[1][0]=1;
	rep(i,k){
		rep0(j,k){
			f[i+1][j]=(f[i+1][j]+f[i][j]*a)%mod;
			if(i+j<k)f[i][j+i]=(f[i][j+i]+f[i][j]*b)%mod;
			else {
				ll v=f[i][j]*b%mod;
				p=(p+v*(i+j))%mod;
			}
		}
	}
	ll u=a*Pow(b,mod-2)%mod;
	rep0(j,k){
		ll v=f[k+1][j];
		p=(p+j*v)%mod;
		p=(p+(k+1)*v)%mod;
		p=(p+u*v)%mod;
	}
	printf("%I64d\n",p);
	return 0;
}
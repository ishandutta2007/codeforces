#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=(b);i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
ll m,x,p[22],a[22],b[22],len,res=1;
map<ll,int>Map[22];
inline void init(ll n){
	for(register ll i=2;i*i<=n;i++)if(n%i==0){
		len++;p[len]=i;while(n%i==0)n/=i,a[len]++;
	}
	if(n>1)len++,p[len]=n,a[len]=1;
}
inline void init2(ll n,int tp){
	for(register ll i=2;i*i<=n;i++){
		while(n%i==0)Map[tp][i]++,n/=i;
	}
	if(n>1)Map[tp][n]++;
}
inline ll mul(ll a, ll n, ll mo){
	ll res=0;n%=mo;a%=mo;if(mo<=2000000000)return a*n%mo;
	while(n){
		if(n&1)res=res+a<mo?res+a:res+a;
		a=a+a<mo?a+a:a+a-mo;n>>=1;
	}
	return res%mo;
}
inline ll power(ll a, ll n, ll mo){
	ll res=1;if(mo==1)return 0;n%=mo-1;
//	printf("power %lld %lld %lld\n",a,n,mo);
	while(n){
		if(n&1)res=mul(res,a,mo);
		a=mul(a,a,mo);n>>=1;
	}
	return res;
}
inline void dfs(int dep, ll d){
//	printf("dfs %d %lld %lld %lld %lld\n",dep,d,len,b[1],b[2]);
	if(dep>len){
		if(d==1)return;
		map<ll,int>fac;rep(i,1,len)if(b[i]){
			if(b[i]-1)fac[p[i]]+=b[i]-1;
			for(map<ll,int>::iterator it=Map[i].begin();it!=Map[i].end();it++)
				fac[(*it).fi]+=(*it).se;
		}
		static ll c[22];int tot=0;ll phi=1;
		for(map<ll,int>::iterator it=fac.begin();it!=fac.end();it++){
			tot++,c[tot]=(*it).fi;rep(i,1,(*it).se)phi*=c[tot];
		}
		ll k=phi;
		rep(i,1,tot){while(k%c[i]==0&&power(x,k/c[i],d)==1)k/=c[i];}
		res+=phi/k;
		return;
	}
	rep(i,0,a[dep])b[dep]=i,dfs(dep+1,d),d*=p[dep],b[dep]=0;
}
int main(){
	scanf("%lld%lld",&m,&x);init(m);
	rep(i,1,len)init2(p[i]-1,i);
	dfs(1,1);
	cout<<res;
	return 0;
}
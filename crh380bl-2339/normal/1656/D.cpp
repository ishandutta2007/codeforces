#include<bits/stdc++.h>
#define ll long long
#define mytz __builtin_ctzll
using namespace std;
inline ll multi(ll &a,ll &b,ll &m){
    __int128 X=a,Y=b,Z=m;
    X=X*Y%Z;
    return X;
}
inline ll Irand(ll x){
    return 1ull*((rand()<<15^rand())<<30^(rand()<<15^rand()))%x; //2
}
ll KSM(ll a,ll b,ll m){
    ll ans=1LL;
    while(b){
        if(b&1)ans=multi(ans,a,m);
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
bool mr(ll x,ll b){
   	ll k=x-1;
   	while(k){
       	ll cur=KSM(b,k,x);
       	if(cur!=1&&cur!=x-1)return false;
       	if((k&1)==1||cur==x-1)return true;
       	k>>=1;
   	}
   	return true;
}
bool prime(ll x){
   	if(x==46856248255981ll||x<2)return false;
   	if(x==2||x==3||x==7||x==61||x==24251)return true;
   	return mr(x,2)&&mr(x,61);
}
inline ll m_max(ll a,ll b){return a>b?a:b;}
ll ans=0,c,mod;
//inline ll f(ll x){return (multi(x,x,mod)+c)%mod;}
inline ll gcd(ll a,ll b){
    if(!a)return b;
    if(!b)return a;
    register int t=mytz(a|b);
    a>>=mytz(a);
    do{
        b>>=mytz(b);
        if(a>b){ll t=b;b=a,a=t;}
        b-=a;
    }while(b);
    return a<<t;
}
inline ll m_abs(ll x){return x>0?x:-x;}
ll f(ll x,ll c,ll n)
	{
		return ((__int128)x*x+c)%n;
	}
	ll find(ll x)
	{
		ll s=0,t=0,c=1ll*rand()%(x-1)+1,val=1;
		for(int gol=1;;gol<<=1,s=t,val=1)
		{
			for(int i=1;i<=gol;++i)
			{
				t=f(t,c,x);
				val=(__int128)val*abs(t-s)%x;
				if((i&127)==0)
				{
					ll d=gcd(val,x);
					if(d>1)return d;
				}
			}
			ll d=gcd(val,x);
			if(d>1)return d;
		}
	}
ll p[1005],s=0;
void Pollard_rho(ll x){// 
	if(x==1)return;
	register ll u;
	while(!prime(x)&&x>1){
		u=find(x);
		while(u==x||!prime(u))u=find(u);
		while(x%u==0){
			x/=u;
			p[++s]=u;
		}
	}
	if(x!=1)p[++s]=x;
}
int main(){
	int T,i;
	ll n,c=1;
	scanf("%d",&T);
	while(T--){
		s=0;
		srand((unsigned)time(0));
		scanf("%lld",&n);
		c=1;
		while(n%2==0){
			n>>=1;
			c<<=1;
		}
		if((c+c+1)<=n){
			printf("%lld\n",c+c);
			continue;
		}
		Pollard_rho(n);
		if(s==0){
			puts("-1");
			continue;
		}
		sort(p+1,p+1+s);
		ll p1=p[1];
		if(p1*(p1+1)<=2LL*n*c){
			printf("%lld\n",p1);
		}
		else puts("-1");
	}
	return 0;
}
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
//ll find(ll p){
//	if(!(p&1))return 2LL;
//	mod=p;
//	register ll a,b,x;
//	while(1){
//		a=b=Irand(p-2)+1,c=Irand(p-2)+1;
//		do{
//			a=f(a);
//			b=f(f(b));
//			x=gcd(m_abs(a-b),p);
//			if(x!=1 and x!=p)return x;
//		}while(a!=b);
//	}
//	return p;
//}
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
ll p[1005],s[100005];
vector<ll>v[1005];
map<ll,int>M;
bool bo[100005],b[1005];
void Pollard_rho(ll x,int i){
	ll y=x;
	if(x==1)return;
	register ll u;
	while(!prime(x)&&x>1){
		u=find(x);
		while(u==x||!prime(u))u=find(u);
		v[i].push_back(u);
		while(x%u==0){
			x/=u;
		}
	}
	if(x!=1)v[i].push_back(x);
}
ll A[1005],B[1005];
int cnt=0,mn=1e9,id=-1;
bool chk(int x){
	int i;
	for(i=0;i<v[x].size();++i){
		if(!bo[M[v[x][i]]])return 0;
	}
	if(!b[x]&&v[x].size()<=mn){
		mn=v[x].size();
		id=x;
	}
	return 1;
}
vector<int>e[100005];
bool used[100005];
int main(){
	int n,i,k,j,tot=0,sum=0;
	scanf("%d%d",&n,&k);
	ll x;
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		B[i]=x;
		Pollard_rho(x,i);
		for(j=0;j<v[i].size();++j){
			if(!M[v[i][j]])M[v[i][j]]=++tot;
		}
	}
	for(i=1;i<=n;++i){
		if(v[i].size()==1){
			int t1=M[v[i][0]];
			int tmp=++s[t1];
			if(tmp<=2)b[i]=1;
			if(tmp==2){
				bo[t1]=1;
				++sum;
			}
		}
	}
	for(i=1;i<=n;++i){
		if(chk(i)){
			++cnt;
			if(b[i])e[M[v[i][0]]].push_back(i);
		}
	}
	if(k>cnt)puts("0");
	else if(k%2==1&&k<mn*2)puts("0");
	else{
		if(k>=sum*2){
			k-=sum*2;
			for(i=1;i<=tot;++i){
				for(j=0;j<e[i].size();++j){
					printf("%lld ",B[e[i][j]]);
					used[e[i][j]]=1;
				}
			}
			for(i=1;i<=n;++i){
				if(k&&!used[i]&&chk(i)){
					printf("%lld ",B[i]);
					--k;
				}
			}
		}
		else if(k%2==0){
			for(i=1;i<=tot;++i){
				for(j=0;j<e[i].size();++j){
					if(k){
						--k;
						printf("%lld ",B[e[i][j]]);
					}
				}
			}
		}
		else{
			assert(~id);
			printf("%lld ",B[id]);
			used[id]=1;
			--k;
			for(i=1;i<=tot;++i){
				for(j=0;j<e[i].size();++j){
					if(B[id]%v[e[i][j]][0]==0){
						if(!k)continue;
						--k;
						printf("%lld ",B[e[i][j]]);
						used[e[i][j]]=1;
					}
				}
			}
			for(i=1;i<=tot;++i){
				for(j=0;j<e[i].size();++j){
					if(k&&!used[e[i][j]]){
						used[e[i][j]]=1;
						--k;
						printf("%lld ",B[e[i][j]]);
					}
				}
			}
		}
	}
	return 0;
}
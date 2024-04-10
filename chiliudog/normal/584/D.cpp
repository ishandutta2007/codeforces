#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1000005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
bool flag[maxn];
int prime[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
namespace mathfunctions{
	typedef int ll;
	const int S=10;
	#define F(x) ((mul(x,x,n)+c)%(n))
	inline ll mul(ll x,ll y,ll mod){
		return (x*y-(ll)(((long double)x*y)/mod)*mod)%mod;
	}
	inline ll power(ll x,ll n,ll mod){
		ll ans=1;
		while(n){
			if (n&1) ans=(long long)ans*x%mod;
			x=(long long)x*x%mod;n>>=1;
		}
		return ans;
	}
	inline ll random(ll lim){
		ll x=rand()%lim;
		fortodo(_,1,4) x=(x*rand()%lim+rand()+lim)%lim;
		return x;
	}
	inline ll gcd(ll a,ll b){
		if (b==0) return a;return gcd(b,a%b);
	}
	inline bool check(ll a,ll n,ll x,ll t){
		ll tmp=power(a,x,n),last=tmp;
		fortodo(i,1,t){
			tmp=mul(tmp,tmp,n);if (tmp==1&&last!=1&&last!=n-1) return 1;last=tmp;
		}
		if (tmp!=1) return 1;return 0;
	}
	inline bool is_prime(ll n){
		if (n<2) return 0;if (n==2) return 1;if ((n&1)==0) return 0;
		ll x=n-1,t=0;
		while((x&1)==0) x>>=1,t++;
		fortodo(p,1,S){
			ll a=random(n-2)+2;
			if (check(a,n,x,t)) return false;
		}
		return true;
	}
	inline ll rho(ll n,ll c){
		ll x=random(n),y=F(x),t;
		while(x^y){
			t=gcd(n,abs(x-y));
			if (t>1ll && t<n) return t;
			x=F(x);y=F(y);y=F(y);
		}
		return n;
	}
}
using namespace mathfunctions;int tot=0;
int main(){
 //   judge();
	memset(flag,1,sizeof(flag));
	int n;read(n);int t=min(maxn-5,n);
	fortodo(i,2,t){
		if (flag[i])prime[++tot]=i;
		fortodo(j,1,tot){
			if (i*prime[j]>t)break;
			flag[i*prime[j]]=0;
			if (i%prime[j]==0)break;
		}
	}
	if (is_prime(n)){
		printf("1\n%d\n",n);return 0;
	}
	while(true){
		int x=rand()%tot+1,y=rand()%tot+1;
		if (is_prime(n-prime[x]-prime[y])){
			printf("3\n%d %d %d",prime[x],prime[y],n-prime[x]-prime[y]);
			return 0;
		}
	}
    return 0;
}
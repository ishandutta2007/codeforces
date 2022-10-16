#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=1e9+7;
ll t,n,l,r,ans;
ll llim[MAXN],rlim[MAXN],fact[MAXN],inv[MAXN];
ll rtmp[MAXN];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp; 
}
ll C(ll n,ll m){
	if(n<0 || m<0)return 0; 
	if(m>n)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	fact[0]=1;
	rep(i,1,2e5)fact[i]=fact[i-1]*i%mod;
	rep(i,0,2e5)inv[i]=power(fact[i],mod-2);
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		rep(i,1,n){
			llim[i]=i-l;
			rlim[i]=r-i;
		}
		rep(i,1,n){
			rtmp[i]=rlim[n-i+1];
		}
		ans=0;
		ll L=1,R=Min(llim[n],rlim[1]);
		if(L>R){
			printf("0\n");continue;
		}
		//[L,R]
		ll lim=Min(llim[1],rlim[n]); //lim 
		if(lim>=L){
			ans=(ans+(lim-L+1)*C(n,(n+1)/2)*(1+odd(n))%mod)%mod;
		} 
		rep(j,Max(L,lim+1),R){
			//
		//	printf("%d\n",j);
			int lcnt=lower_bound(llim+1,llim+1+n,j)-llim-1; //lcntr
			int rcnt=lower_bound(rtmp+1,rtmp+1+n,j)-rtmp-1; //rcntl
		//	printf("lcnt:%d rcnt:%d\n",lcnt,rcnt);
		//	printf("%d %d\n",(n+1)/2,n-(n+1)/2);
			if(lcnt+rcnt>n)break;
			ans=(ans+C(n-lcnt-rcnt,(n+1)/2-rcnt))%mod;
			if(odd(n))ans=(ans+C(n-lcnt-rcnt,n-(n+1)/2-rcnt))%mod; 
		//	printf("ans:%d\n",ans);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
/*
1
4 -3 5
*/
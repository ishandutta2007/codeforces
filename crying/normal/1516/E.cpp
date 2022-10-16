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
const int MAXN=410,mod=1e9+7;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);
	tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp;
}
ll fact[MAXN],inv[MAXN];
ll n,k,dp[MAXN][MAXN],c[MAXN][MAXN];
ll g[MAXN][MAXN],ret[MAXN];
ll Combine(ll n,ll k){
	if(n<k)return 0;
	ll ret=1;
	rep(i,1,k){
		ret=ret*(n-i+1)%mod;
	}
	return ret*inv[k]%mod;
}
int main(){
	fact[0]=inv[0]=1;
	rep(i,1,400){
		fact[i]=fact[i-1]*i%mod;
		inv[i]=power(fact[i],mod-2);
	}
	c[0][0]=1;
	rep(i,1,400){
		c[i][0]=1;
		rep(j,1,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	cin>>n>>k;
	dp[0][0]=1;
	rep(i,1,Min(n,k*2)){
		dp[i][0]=1;
		rep(j,1,k){
			dp[i][j]=(dp[i-1][j]+(i-1)*dp[i-1][j-1]%mod)%mod;
		}
	}
	rep(i,1,Min(n,k*2)){
		rep(j,1,k){
			//ik 
			rep(x,0,i){
				g[i][j]=(g[i][j]+(even(x)?1:mod-1)*c[i][x]%mod*dp[i-x][j]%mod)%mod;	
			}
			ret[j]=(ret[j]+Combine(n,i)*g[i][j]%mod)%mod; 
		}
	}
	ret[0]=1;
	rep(i,1,k){
		ll ans=0;
		rep(j,0,i){
			if(even(j) == even(i)){
				ans=(ans+ret[j])%mod;
			}
		}
		printf("%lld ",ans);
	}
	return 0;
}
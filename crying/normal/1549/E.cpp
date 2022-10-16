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
const ll MAXN=1e6+10,mod=1e9+7,LIM=3e6;
ll n,q,x,fact[MAXN*3],inv[MAXN*3];
ll f[MAXN*3][3];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp;
}
il ll C(ll n,ll m){
	if(n<m)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	scanf("%lld%lld",&n,&q);
	fact[0]=inv[0]=1;
	rep(i,1,n*3)fact[i]=fact[i-1]*i%mod;
	inv[3*n]=power(fact[3*n],mod-2);
	per(i,3*n-1,1){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	inv[3*n+1]=power(3,mod-2);
	f[0][0]=f[0][1]=f[0][2]=n;
	rep(i,1,n*3-1){
		f[i][0]=(C(3*n,i+1)-2*f[i-1][0]-f[i-1][1]+mod+mod+mod)*inv[3*n+1]%mod;
		f[i][1]=(f[i][0]+f[i-1][0])%mod;
		f[i][2]=(f[i][1]+f[i-1][1])%mod; 
	}
	rep(i,1,q){
		scanf("%lld",&x);
		printf("%lld\n",(f[x][0]+C(3*n,x))%mod);
	}
	return 0;
}
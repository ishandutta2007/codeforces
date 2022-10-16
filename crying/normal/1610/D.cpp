#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
ll fact[MAXN],inv[MAXN];
ll n,a[MAXN],c1,c2;
ll cnt[MAXN],ans;
ll f[MAXN][2][2];
ll C(ll n,ll m){
	if(m>n)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
void dp(){
	rep(i,1,30){
		//gcd contains 2^i exactly
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		rep(j,1,c2){
			rep(mask1,0,1)rep(mask2,0,1){
				ll& ret=f[j][mask1][mask2];
				//choose 
				if(cnt[j]>i){
					ret=(ret+f[j-1][mask1][mask2])%mod;
				}
				if(cnt[j]==i){
					if(mask1==1){
						ret=(ret+f[j-1][0][mask2^1])%mod;
						ret=(ret+f[j-1][1][mask2^1])%mod;
					}
				}
				//not choose
				ret=(ret+f[j-1][mask1][mask2])%mod;
			}
		}
		ans=(ans+f[c2][1][0])%mod;
	}
}
int main(){
	fact[0]=inv[0]=1;
	rep(i,1,2e5)fact[i]=fact[i-1]*i%mod;
	inv[(int)2e5]=power(fact[(int)2e5],mod-2);
	per(i,2e5-1,1){inv[i]=inv[i+1]*(i+1)%mod; }
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		ll ret=0,num=a[i];
		while(num%2==0){
			num/=2;
			ret++;
		}
		if(!ret)c1++;
		else cnt[++c2]=ret;
	}
	rep(i,1,n){
		ans=(ans+C(n,i)-C(c2,i)+mod)%mod;
	}
	dp();
	
	printf("%lld\n",ans);
	
	return 0;
}
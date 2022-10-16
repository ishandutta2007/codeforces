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
const int MAXN=2e5+10,mod=998244353;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
ll fact[MAXN],inv[MAXN];
ll n,c1,c2;
ll ww,bb;
string s[MAXN];
ll C(ll n,ll m){
	if(m<0 || n<m)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod; 
}
ll ans;
int check(string a,string b){
	rep(j,0,1){
		if(a[j]=='?')continue;
		if(a[j]!=b[j])return 0;
	}
	return 1;
}
int main(){
	fact[0]=inv[0]=1;
	rep(i,1,2e5)fact[i]=fact[i-1]*i%mod,inv[i]=power(fact[i],mod-2);
	cin>>n;rep(i,1,n)cin>>s[i];
	rep(i,1,n)rep(j,0,1){
		if(s[i][j]=='W')c1++;
		else if(s[i][j]=='B')c2++;
	}
	rep(i,1,n)if(s[i]=="WW")ww++;else if(s[i]=="BB")bb++;
	if(c1>n || c2>n)return printf("0"),0;
	ans=C(n*2-c1-c2,n-c2);
	if(!ww && !bb){
		ll mult=1;
		rep(i,1,n)if(s[i]=="??")mult=mult*2%mod;
		ans=(ans-mult+mod)%mod;
		int flag;
		//all WB 
		flag=1;
		rep(i,1,n){
			if(!check(s[i],"WB"))flag=0;	
		}
		ans=(ans+flag)%mod;
		//all BW
		flag=1;
		rep(i,1,n){
			if(!check(s[i],"BW"))flag=0;
		}
		ans=(ans+flag)%mod;
		
	}
	printf("%lld",ans);
	return 0;
}
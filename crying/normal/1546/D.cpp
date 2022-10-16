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
const int MAXN=1e5+10,mod=998244353,lim=1e5;
ll t,n,fact[MAXN],inv[MAXN];
char s[MAXN];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp;
}
ll C(ll n,ll m){
	return (n<m)?0:fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	fact[0]=1;inv[0]=1;
	rep(i,1,lim){
		fact[i]=fact[i-1]*i%mod;
		inv[i]=power(fact[i],mod-2);
	}
	cin>>t;
	while(t--){
		cin>>n>>(s+1);
		ll cnt1=0,cnt2=0;
		rep(i,1,n-1){
			if(s[i]=='1' && s[i+1]=='1'){
				cnt1++;
				i++;
			}
		}
		rep(i,1,n)cnt2+=(bool)(s[i]=='0');
		cout<<C(cnt1+cnt2,cnt1)<<endl; 
	}

	return 0;
}
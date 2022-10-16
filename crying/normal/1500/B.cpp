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
const int MAXN=1e6+10;
ll n,m,k,a[MAXN],b[MAXN];
ll t[2][MAXN],minn[MAXN],add;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void exgcd(ll a,ll b,ll& x0,ll& y0){
	if(!b){x0=1;y0=0;return;}
	exgcd(b,a%b,x0,y0);
	ll x=y0,y=x0-(a/b)*y0;
	x0=x,y0=y;
}
ll mul(ll a,ll b,ll mod){
	ll res=0;
    while(b>0){
        if(b&1)res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return (res%mod+mod)%mod;
}
ll Calc(ll i,ll j){
	ll minx=i,add=n; 
	ll c=j-minx,d=gcd(add,m);
	if(c%d)return -1;
	ll x,y;exgcd(add,m,x,y);
	ll add2=m/d,mult=c/d;
	if(mult>=0)mult%=add2;
	else mult=mult+((-mult+add2-1)/add2)*add2;
	x=mul(x,mult,add2);
	if(x>=0)x%=add2;
	else x=x+((-x+add2-1)/add2)*add2;
	minx=minx+add*x;
	add=lcm(n,m);
	if(minx>=0)minx%=add;
	else minx=minx+((-minx+add-1)/add)*add;
	if(!minx)minx=add;
	return minx;
}
bool check(ll mid){
	ll cnt=mid;
	rep(i,1,n){
		if(!t[1][a[i]])continue;
		if(minn[i]>mid || minn[i]==-1)continue;
		cnt-=(1+(mid-minn[i])/add);
	}
	return cnt>=k;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	rep(i,1,n){scanf("%lld",&a[i]);t[0][a[i]]=i;}
	rep(i,1,m){scanf("%lld",&b[i]);t[1][b[i]]=i;}
	ll L=1,R=3e18,ans;add=lcm(n,m);
	rep(i,1,n){
		if(!t[1][a[i]])continue;
		minn[i]=Calc(i,t[1][a[i]]); 
	}
	while(L<=R){
		ll mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;R=mid-1;
		}else{L=mid+1;}
	}
	printf("%lld",ans);
	return 0;
}
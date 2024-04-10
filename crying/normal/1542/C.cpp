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
const int moder=1e9+7;
ll t,n,ans,GCD[50],LCM[50];
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	cin>>t;
	GCD[1]=LCM[1]=1;
	rep(i,2,42)LCM[i]=lcm(LCM[i-1],i);
	while(t--){
		cin>>n;ans=0;
		rep(i,1,40){
			//1~ii+1 
			if(LCM[i]>n)break;
			ll cnt=0;
			cnt=n/LCM[i];
			cnt-=n/LCM[i+1];
			cnt%=moder;
			ans=(ans+cnt*(i+1)%moder)%moder;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
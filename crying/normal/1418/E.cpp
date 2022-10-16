#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,moder=998244353;
int n,m,d[MAXN],a[MAXN],b[MAXN];
ll sum[MAXN];
ll ans;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);
	tmp=tmp*tmp%moder;
	if(n&1)tmp=tmp*a%moder;
	return tmp;
}
int main(){
	cin>>n>>m;
	rep(i,1,n){
		cin>>d[i];
	}
	rep(i,1,m){
		cin>>a[i]>>b[i];
	}
	sort(d+1,d+1+n);
	rep(i,1,n){
		sum[i]=sum[i-1]+d[i];
		sum[i]%=moder;
	}
	rep(i,1,m){
		ll ans=0,pb=0;
		ll k1=lower_bound(d+1,d+1+n,b[i])-d-1;
		ll k2=n-k1;
		//max(k2-a[i],0)/k2
		pb=Max(k2-a[i],0)*power(k2,moder-2)%moder;
		ans=(ans+pb*(sum[n]-sum[k1]+moder)%moder)%moder;
		//max(k2+1-a[i],0)/k2+1
		pb=Max(k2+1-a[i],0)*power(k2+1,moder-2)%moder;
		ans=(ans+pb*sum[k1]%moder)%moder;
		printf("%lld\n",ans);
	}
	return 0;
}
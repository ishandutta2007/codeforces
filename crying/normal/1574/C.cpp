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
const ll MAXN=2e5+10,INF=4e18;
ll n,m,sum,a[MAXN],x[MAXN],y[MAXN];
void solve(ll x,ll y){
	//ai >= x
	ll ans=INF;
	ll pos=lower_bound(a+1,a+1+n,x)-a;
	if(a[n]<x)pos=n+1;
	if(pos<=n)ans=min(ans,max(0LL,y-(sum-a[pos])));
	if(pos==1){printf("%lld\n",ans);return;}
	//ai < x
	//1.ai >= sum-y
	ll pos2=lower_bound(a+1,a+1+n,sum-y)-a;
	if(a[pos-1]<sum-y)pos2=pos;
	if(pos2<pos){
		//[pos2,pos)
		ans=min(ans,x+y-sum);
	}
	//2.ai < sum-y
	if(pos2!=1){
		//[1,pos2)
		ans=min(ans,max(0LL,x-a[pos2-1]));
	}
	printf("%lld\n",ans);
}
int main(){
	cin>>n;
	rep(i,1,n){cin>>a[i];sum+=a[i];}
	sort(a+1,a+1+n);
	cin>>m;
	rep(i,1,m){cin>>x[i]>>y[i];}
	rep(i,1,m){
		solve(x[i],y[i]);
	}

	return 0;
}
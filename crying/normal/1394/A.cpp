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
const int MAXN=1e5+10;
ll n,d,m,tmp,ans;
vector<ll>a1,a2;
ll sum1[MAXN],sum2[MAXN];
int main(){
	cin>>n>>d>>m;
	rep(i,1,n){
		cin>>tmp;
		if(tmp<=m)a1.pb(tmp);
		else a2.pb(tmp);
	}
	sort(a1.begin(),a1.end(),greater<ll>());
	sort(a2.begin(),a2.end(),greater<ll>());
	rep(i,1,a1.size())sum1[i]=sum1[i-1]+a1[i-1];
	rep(i,1,a2.size())sum2[i]=sum2[i-1]+a2[i-1];
	rep(i,0,a2.size()){
		ll days=i+(i-1)*d;
		if(days>n)break;
		ans=Max(ans,sum2[i]+sum1[Min(n-days,a1.size())]);
	}
	printf("%lld",ans);
	return 0;
}
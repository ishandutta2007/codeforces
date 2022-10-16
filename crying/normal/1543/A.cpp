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
ll t,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(!a || !b){printf("%lld 0\n",abs(a-b));continue;}
		if(a==b){printf("0 0\n");continue;}
		ll d=abs(b-a),ans=1e18+2;
		if(b>=a%d)ans=min(ans,a%d);
		if(a>=b%d)ans=min(ans,b%d);
		if(b>=d-(a%d))ans=min(ans,d-(a%d));
		if(a>=d-(b%d))ans=min(ans,d-(b%d));
		printf("%lld %lld\n",d,ans);

	}

	return 0;
}
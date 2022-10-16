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
const ll MAXN=3e5+10,INF=1e18;
ll T,n,k,a[MAXN],t[MAXN],val[MAXN],f[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n){a[i]=t[i]=val[i]=0;f[i]=INF;}
		rep(i,1,k){
			cin>>a[i];
		}
		rep(i,1,k){
			cin>>t[i];
		}
		rep(i,1,k){
			val[a[i]]=t[i];
		}
		ll minn=INF;
		rep(i,1,n){
			if(val[i]){
				minn=Min(minn,val[i]-i);
			}
			f[i]=Min(f[i],i+minn);
		}
		minn=INF;
		per(i,n,1){
			if(val[i]){
				minn=Min(minn,val[i]+i);
			}
			f[i]=Min(f[i],-i+minn);
		}
		rep(i,1,n)printf("%lld ",f[i]);
		printf("\n");
	}

	return 0;
}
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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,l,r,c[MAXN];
int t[MAXN],ans; 
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&l,&r);
		rep(i,1,n){t[i]=0;
			scanf("%lld",&c[i]);
		}
		rep(i,1,n)t[c[i]]+=((i<=l)?1:-1);
		rep(i,1,n)ans+=abs(t[i]); 
		if(l<r){
			ans=r-l;
			rep(i,1,n)ans+=abs(t[i]); 
			rep(i,l+1,n){
				if(l==r)break;
				if(t[c[i]]<=-2){
					l++,r--,t[c[i]]+=2,ans-=2;
				}
			}
			ans/=2;
		}else{
			ans=l-r;	
			rep(i,1,n)ans+=abs(t[i]); 
			per(i,l,1){
				if(l==r)break;
				if(t[c[i]]>=2){
					l--,r++,t[c[i]]-=2,ans-=2;
				}
			}
			ans/=2;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
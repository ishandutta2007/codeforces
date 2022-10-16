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
const int MAXN=2010,INF=1e9;
int T,n,k,a[MAXN];
int f[MAXN][MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n){
			cin>>a[i]; 
		}
		rep(i,1,n)f[0][i]=-INF;
		f[0][0]=0;
		rep(i,0,n-1){
			rep(j,0,n)f[i+1][j]=-INF;
			rep(j,0,i){
				f[i+1][j]=Max(f[i+1][j],f[i][j]+(bool)(a[i+1]==i+1-j));
				f[i+1][j+1]=Max(f[i+1][j+1],f[i][j]);
			}
		}
		ll ans=-1;
		rep(i,0,n){
			if(f[n][i]>=k){
				ans=i;break;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
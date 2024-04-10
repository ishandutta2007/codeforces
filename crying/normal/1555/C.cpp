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
const int MAXN=1e5+10,INF=2e9;
ll T,m,a[3][MAXN],pre[MAXN],suf[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>m;
		rep(i,1,2){
			rep(j,1,m)cin>>a[i][j];
		}
		pre[0]=0;
		rep(i,1,m){
			pre[i]=pre[i-1]+a[2][i];
		}
		suf[m+1]=0;
		per(i,m,1){
			suf[i]=suf[i+1]+a[1][i];
		}
		ll ans=INF;
		rep(i,1,m){
			ans=Min(ans,Max(pre[i-1],suf[i+1]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
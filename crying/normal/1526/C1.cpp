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
const ll MAXN=2010,INF=1e18;
ll n,a[MAXN],f[MAXN][MAXN];
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,0,n)rep(j,0,n)f[i][j]=-INF;
	f[0][0]=0;
	rep(i,1,n){
		f[i][0]=0;
		rep(j,1,i){
			f[i][j]=f[i-1][j];
			if(f[i-1][j-1]+a[i]>=0)f[i][j]=Max(f[i][j],f[i-1][j-1]+a[i]);
		}
	}
	int ans=0;
	rep(j,1,n){
		if(f[n][j]>=0)ans=j;
	}
	cout<<ans;
	return 0;
}
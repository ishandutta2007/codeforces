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
const int MAXN=510,mod=998244353;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp;
}
ll n,x,f[MAXN][MAXN],c[MAXN][MAXN],g[MAXN][MAXN];
void dp(){
	rep(i,2,n){
		rep(j,1,x){
			if(j<i){
				f[i][j]=power(j,i);
				continue;
			}
			f[i][j]=power(i-1,i);
			rep(cnt,0,i-1){
				ll val=c[i][cnt]*g[i-1][cnt]%mod;
				val=val*f[i-cnt][j-(i-1)]%mod;
				f[i][j]=(f[i][j]+val)%mod;
			}
		}
	}
}
int main(){
	c[0][0]=1;
	rep(i,1,500){
		c[i][0]=1;
		rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		rep(j,0,500){
			g[i][j]=power(i,j);
		}
	}
	cin>>n>>x;
	dp();
	cout<<f[n][x];

	return 0;
}
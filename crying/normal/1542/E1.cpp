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
const int MAXN=510,MAXM=510*510,ADD=501*501/2+1;
ll n,mod;
ll f[2][MAXM],sum[2][MAXM],fact[MAXN],c[MAXN][MAXN],g[MAXN],ans[MAXN],s[MAXM];
int main(){
	cin>>n>>mod;
	fact[0]=1;
	rep(i,1,n){
		fact[i]=fact[i-1]*i%mod;
	}
	c[0][0]=1;
	rep(i,1,n){
		c[i][0]=1;
		rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	//f[i][j]ij 
	f[1&1][0+ADD]=1;rep(j,0,n*(n-1)/2)sum[1&1][j+ADD]=1;
	rep(i,2,n){
		memset(sum[i&1],0,sizeof sum[i&1]);
		rep(k,0,i-1){
			f[i&1][-i*(i-1)/2+ADD]=((ll)f[i&1][-i*(i-1)/2+ADD]+(i-k)*f[(i-1)&1][-i*(i-1)/2+k+ADD])%mod;
		}
		rep(j,-(i*(i-1)/2)+1,i*(i-1)/2){
			f[i&1][j+ADD]=((ll)f[i&1][j-1+ADD]+sum[(i-1)&1][Min(j+i-1,n*(n-1)/2)+ADD]-sum[(i-1)&1][j-1+ADD]-
			sum[(i-1)&1][j-1+ADD]+sum[(i-1)&1][Max(j-i-1,-n*(n-1)/2)+ADD]+mod)%mod;
		}
		rep(j,-n*(n-1)/2,n*(n-1)/2)sum[i&1][j+ADD]=(sum[i&1][j-1+ADD]+f[i&1][j+ADD])%mod;
		memset(s,0,sizeof s);
		s[i*(i-1)/2+ADD]=f[i&1][i*(i-1)/2+ADD];
		per(j,i*(i-1)/2-1,-n*(n-1)/2){
			s[j+ADD]=(s[j+1+ADD]+f[i&1][j+ADD])%mod;
		}
		rep(x,1,i+1){
			rep(y,x+1,i+1){
				//x,y
				ll diff=y-x;
				g[i+1]=(g[i+1]+s[diff+1+ADD])%mod;
			}
		}
	}
	rep(i,2,n){
		ans[i]=((ll)ans[i-1]*i+g[i])%mod;
	}
	cout<<ans[n];
	return 0;
}
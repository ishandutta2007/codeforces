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
const int MAXN=15,MAXM=(1<<14),mod=1e9+7;
int n,a[MAXN],inv[(int)(2e6+10)];
int ans,h[MAXN][MAXM],f[MAXN][MAXM];
il int g(int S,int T){
	int ret=1;
	rep(i,0,n-1){
		if(!(S&(1<<i)))continue;
		ret=1LL*ret*h[i][T]%mod;
	}
	return ret;
}
void solve(){
	//h
	rep(i,0,n-1){
		rep(j,1,(1<<n)-1){
			if(j&(1<<i))continue;
			h[i][j]=1;
			rep(k,0,n-1){
				if(j&(1<<k)){
					h[i][j]=1LL*h[i][j]*a[k]%mod*inv[a[i]+a[k]]%mod;
				}
			}
		}
	} 
	rep(i,0,n-1){
		rep(j,1,(1<<n)-1){
			if(!(j&(1<<i)))continue;
			f[i][j]=1;
			for(int k=j;k;k=(k-1)&j){
				if(k==j || !(k&(1<<i)))continue;
				f[i][j]=(f[i][j]-1LL*f[i][k]*g(k,k^j)%mod+mod)%mod;
			}
		} 
	}
}
int main(){
	inv[1]=1;
	rep(i,2,2e6){
		inv[i]=((1LL*-(mod/i)*inv[mod%i])%mod+mod)%mod;
	}
	scanf("%d",&n);
	rep(i,0,n-1)scanf("%d",&a[i]);
	solve();
	rep(i,0,n-1){
		ans=(ans+f[i][(1<<n)-1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
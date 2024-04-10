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
typedef double db;
using namespace std;
const int MAXN=2100,MAXM=60,mod=998244353;
int power(int a,int n){
	if(!n)return 1;
	int tmp=power(a,n/2);tmp=1ll*tmp*tmp%mod;
	if(n&1)tmp=1ll*tmp*a%mod;return tmp;
}
int n,k,b[MAXN];
int fact[MAXN],inv[MAXN];
int f[2][MAXN][MAXN],l[MAXN],r[MAXN],ans;
int g[2][MAXN*2][MAXN];
int main(){
//	freopen("in.in","r",stdin);
	fact[0]=inv[0]=1;
	rep(i,1,2000)fact[i]=1ll*i*fact[i-1]%mod;
	inv[2000]=power(fact[2000],mod-2);
	per(i,1999,1)inv[i]=1ll*(i+1)*inv[i+1]%mod;
	cin>>n>>k;
	rep(i,1,n)cin>>b[i],l[i]=max(0,b[i]-k),r[i]=min(i,b[i]+k);
	f[0][0][0]=g[0][0][0]=1;
	rep(i,1,n){
		if(i>1)rep(j,0,i-2)rep(k,l[i-2],r[i-2])f[i&1][j][k]=g[i&1][j+k][k]=0;
		per(x,i,0)rep(y,l[i],r[i]){
			if(y+x>i)break;
			int& ret=f[i&1][x][y];
			ret=(ret+1ll*(x+y)*f[(i-1)&1][x][y])%mod;
			if(x)ret=(ret+1ll*f[(i-1)&1][x-1][y])%mod;
			//x=j-(t-k-1),y=t
			int R=Min(Min(r[i-1],y-1),x+y-1);
			if(R>=l[i-1]){
				ret=(ret+1ll*g[(i-1)&1][x+y-1][R]*inv[x])%mod;
			}
			g[i&1][x+y][y]=(g[i&1][x+y][y-1]+1ll*ret*fact[x])%mod; 
		}
	}
	rep(j,0,n)rep(k,l[n],r[n]){
		if(k+j>n)continue;
		ans=(ans+1ll*f[n&1][j][k]*fact[n-k]%mod*inv[n-k-j])%mod;
	}
	cout<<ans;
	return 0;
}
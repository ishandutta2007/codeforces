#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=4e3+10,K=8e2+10;
int n,k,sum[N][N],dp[K][N];
int calc(int u,int v){return sum[v][v]-sum[v][u-1]-sum[u-1][v]+sum[u-1][u-1];}
void solve(int s,int l,int r,int opl,int opr){
	if(l>r)return;
	pair<int,int>best=mp(0x3f3f3f3f,0);
	for(int i=opl;i<=min(mid,opr);i++)
		chkmn(best,mp(dp[s-1][i-1]+calc(i,mid),i));
	dp[s][mid]=best.fi;
	solve(s,l,mid-1,opl,best.se);
	solve(s,mid+1,r,best.se,opr);
}
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			read(sum[i][j]),sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	memset(dp[0],0x3f,sizeof dp[0]);dp[0][0]=0;
	for(int i=1;i<=k;i++)solve(i,1,n,1,n);
	writeln(dp[k][n]/2);
}
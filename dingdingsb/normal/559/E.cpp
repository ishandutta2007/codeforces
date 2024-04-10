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
const int N=1e2+10;
int n;pair<int,int>a[N];
int dp[N][N][2];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i].fi,a[i].se);
	sort(a+1,a+1+n);a[0].fi=-1e9;
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int d=0;d<2;d++){
				chkmx(ans,dp[i][j][d]);
				int ed=a[j].fi+d*a[j].se;
				tuple<int,int,int>mx=mt(-1e9,0,0);
				for(int k=i+1;k<=n;k++)
					for(int p=0;p<2;p++){
						int ee=a[k].fi+p*a[k].se;
						chkmx(mx,mt(ee,k,p));
						chkmx(dp[k][get<1>(mx)][get<2>(mx)],dp[i][j][d]+get<0>(mx)-ee+min(a[k].se,ee-ed));
					}
			}
	writeln(ans);
}
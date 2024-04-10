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
const int N=1e3+100;
typedef double db;
int n;db E[N],prod[N],p[N][N];bool vis[N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)read(p[i][j]),p[i][j]/=100;
	if(n==1)return puts("0"),0;
	vis[n]=1;for(int i=1;i<n;i++)prod[i]=1-p[i][n],E[i]=1;
	while(1){
		pair<db,int>mn=mp(1e20,0);
		for(int i=1;i<=n;i++)if(!vis[i])chkmn(mn,mp(E[i]/(1-prod[i]),i));
		int j=mn.se;E[j]/=1-prod[j];vis[j]=1;
		if(j==1)return printf("%.10lf",E[1]),0;
		for(int i=1;i<=n;i++)if(!vis[i])
			E[i]+=p[i][j]*E[j]*prod[i],prod[i]*=1-p[i][j];
	}
}
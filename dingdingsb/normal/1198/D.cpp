// Problem: CF1198D Rectangle Painting 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1198D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
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
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=52;
int n;char s[N][N];
int dp[N][N][N][N];
int dfs(int x1,int y1,int x2,int y2){
	if(~dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
	if(x1==x2&&y1==y2)return dp[x1][y1][x2][y2]=(s[x1][y1]=='#');
	int&res=dp[x1][y1][x2][y2];
	res=max(x2-x1+1,y2-y1+1);
	for(int x=x1;x<x2;x++)chkmn(res,dfs(x1,y1,x,y2)+dfs(x+1,y1,x2,y2));
	for(int y=y1;y<y2;y++)chkmn(res,dfs(x1,y1,x2,y)+dfs(x1,y+1,x2,y2));
	return res;
}
signed main(){
	memset(dp,0xff,sizeof dp);
	read(n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	write(dfs(1,1,n,n));
}
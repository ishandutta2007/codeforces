#include<bits/stdc++.h>
#define mp make_pair
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
typedef __int128 lll;
#define lowbit(x) ((x)&-(x))
const int N=1e3+10;
const int pr[11]={0,2,3,5,7,11,13,17,19,23,29};
int n;
const lll inf=1e18;
lll dp[15][N];
vector<int>facs[N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)if(n%i==0)
		for(int j=1;j<=i;j++)facs[i].pb(j);
	memset(dp,0x3f,sizeof dp);
	dp[0][1]=1;
	for(int i=1;i<=10;i++){
		//
		memcpy(dp[i],dp[i-1],sizeof dp[i]);
		lll now=pr[i];
		for(int j=1;j<=n&&now<=inf;j++,now*=pr[i])if(n%(j+1)==0)
			for(auto k:facs[n/(j+1)])if(dp[i-1][k]<=inf&&dp[i-1][k]*now<=inf)
				chkmn(dp[i][k*(j+1)],dp[i-1][k]*now);
		//for(int j=1;j<=n;j++)if(dp[i][j]<=inf)
		//	writeln(i,j,dp[i][j]);
	}
	write(dp[10][n]);
}
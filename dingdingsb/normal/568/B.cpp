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
#define lowbit(x) ((x)&-(x))
const int mod=1e9+7;
const int N=4100;
struct mint{
	int x;
	mint(int o=0){x=o;}
	mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}
	friend mint operator+(mint a,mint b){return a+=b;}
	friend mint operator*(mint a,mint b){return a*=b;}
}dp[N][N],C[N][N];
int n;
signed main(){
	read(n);
	dp[0][0]=1;C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j],
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	mint ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			ans+=C[n][i]*dp[i][j];
	write(ans.x);
}
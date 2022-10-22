// Problem: E. Pchelyonok and Segments
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100,M=610;
const int inf=0x3f3f3f3f3f3f3f3f;
int t,n,a[N],sum[N];
int dp[N][M];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]),sum[i]=sum[i-1]+a[i];
		int k=0;
		while((1+k)*k/2<n)k++;
		for(int i=0;i<=n+1;i++)for(int j=0;j<=k;j++)
			dp[i][j]=-inf;
		dp[n+1][0]=inf;
		for(int i=n;i;i--){
			for(int j=0;j<=k;j++)dp[i][j]=dp[i+1][j];
			for(int j=1;j<=k;j++)if(i+j<=n+1)
				if(sum[i+j-1]-sum[i-1]<dp[i+j][j-1])
					chkmx(dp[i][j],sum[i+j-1]-sum[i-1]);
		}
		for(int j=k;~j;j--)if(dp[1][j]!=-inf){
			write(j);break;
		}
		pc('\n');
	}
}
// Problem: F1. Korney Korneevich and XOR (easy version)
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/F1
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100,M=1024;
int n,a[N];
int dp[N][M];
signed main(){
	memset(dp,0x3f,sizeof dp);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	dp[0][0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=0;j<M;j++)
			dp[i][j]=dp[i-1][j];
		for(int j=0;j<M;j++)
			if((j^a[i])<M)
				if(dp[i-1][j^a[i]]<a[i])
					chkmn(dp[i][j],a[i]);
	}
	vector<int>ans;
	for(int i=0;i<M;i++)if(dp[n][i]!=0x3f3f3f3f)
		ans.pb(i);
	write(ans.size());pc('\n');
	for(auto x:ans)write(x),pc(' ');
}
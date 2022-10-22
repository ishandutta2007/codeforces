// Problem: C. Coin Rows
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=1e5+100;
int t,n,a[3][N],sum[3][N];
signed main(){
	read(t);
	while(t--){
		read(n);
		sum[1][0]=sum[2][0]=sum[1][n+1]=sum[2][n+1]=0;
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
				read(a[i][j]);
		for(int i=1;i<=n;i++)sum[2][i]=sum[2][i-1]+a[2][i];
		for(int i=n;i>=1;i--)sum[1][i]=sum[1][i+1]+a[1][i];
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)ans=min(ans,max(sum[1][i+1],sum[2][i-1]));
		write(ans);putchar('\n');
	}
	return 0;
	cout<<"ccfn***";
}
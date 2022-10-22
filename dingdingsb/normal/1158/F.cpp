// Problem: CF1158F Density of subarrays
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1158F
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// Author: Juruo_cjl
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
typedef long long ll;
const int mod=998244353;
const ll mod2=1ll*mod*mod*7;
int ksm(int x,int y=mod-2){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}return res;
}
const int N=3000+10,B=11;
int n,c,m;int a[N];
int add(int x,int y){if(x+y>=mod)return x+y-mod;return x+y;}
int dec(int x,int y){if(x-y<0)return x-y+mod;return x-y;}
namespace solve1{
	// c>B
	int pow2[N];
	int val[N];
	int ival[N];
	int cnt[N];
	int g[N][N];
	ll s[N][N];
	int dp[N][N];
	void work(){
		pow2[0]=1;for(int i=1;i<=n;i++)pow2[i]=pow2[i-1]*2%mod;
		for(int i=0;i<=n;i++)val[i]=dec(pow2[i],1),ival[i]=ksm(val[i]);
		for(int l=1;l<=n;l++){
			memset(cnt,0,sizeof cnt);
			int ways=1;int _=c-1;
			for(int r=l+1;r<=n;r++){
				cnt[a[r]]++;
				if(a[r]!=a[l]){
					if(cnt[a[r]]==1)_--;
					else ways=1ll*ways*ival[cnt[a[r]]-1]%mod;
					if(!_)g[l][r]=ways;
					ways=1ll*ways*val[cnt[a[r]]]%mod;
				}else ways=add(ways,ways);
			}
		}
		s[n+1][0]=1;
		for(int i=n;i;i--){
			for(int j=1;j<=n-i+1;j++){
				ll tot=0;
				for(int k=i+c-1;k<=n&&s[k+1][j-1];k++)
					tot=(tot+1ll*g[i][k]*s[k+1][j-1])%mod;
				if(!tot)break;
				dp[i][j]=tot;
			}
			dp[i][0]=pow2[n-i];
			for(int j=0;j<=n-i+1;j++)
				s[i][j]=add(s[i+1][j],dp[i][j]);
		}
		s[1][0]=dec(s[1][0],1);
		for(int i=0;i<=n;i++)
			write(dec(s[1][i],s[1][i+1])),putchar(' ');
	}
}
namespace solve2{
	// c<=B
	int f[2][N][1<<B],res[N];
	void work(){
		for(int i=1;i<=n;i++)a[i]--;
		int lim=1<<c;
		int now=0,nxt=1;
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++)for(int k=0;k<lim-1;k++)f[nxt][j][k]=0;
			for(int j=0;j<=m;j++)for(int k=0;k<lim-1;k++){
				int S=k|(1<<a[i+1]);
				if(S==lim-1)S=0;
				f[nxt][j][k]=add(f[nxt][j][k],f[now][j][k]);
				f[nxt][j+!S][S]=add(f[nxt][j+!S][S],f[now][j][k]);
			}
			swap(now,nxt);
		}
		for(int j=0;j<=n;j++)for(int k=0;k<lim-1;k++)res[j]=add(res[j],f[now][j][k]);
		for(int i=0;i<=n;i++)write(dec(res[i],!i)),putchar(' ');
	} 
}
signed main(){
	read(n,c);
	//n=3000,c=12;
	for(int i=1;i<=n;i++)
	read(a[i]);
	//a[i]=rand()%c+1;
	m=n/c;
	if(c>B)solve1::work();
	else solve2::work();
}
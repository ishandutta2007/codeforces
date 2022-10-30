
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
	int x=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
#define maxn 3355
#define mod 1000000007 
long long len,n,p,alpha,a[maxn],x[maxn];
char s[maxn];
int f[maxn][maxn][2][2];
inline int C2(int x){
	return 1ll*x*(x-1)/2%mod; 
}
signed main()
{
	p=read(),alpha=read();
	cin>>s+1;
	n=strlen(s+1);
	if(alpha>3500){
		puts("0");
		return 0;
	}
	For(i,1,n)a[i]=s[n-i+1]-'0';
	while(n)
	{
		long long t=0;
		Rep(i,n,1){
			t=t*10+a[i];
			a[i]=t/p,t%=p;
			if(!a[i]&&i==n)n--;
		}
		x[++len]=t;
	}n=len;
	reverse(x+1,x+n+1);
	f[0][0][0][1]=1;
//	cout<<n<<endl;
//	For(i,1,n)cout<<x[i]<<' ';puts("q");
	For(i,1,n)
	{
		For(j,0,i){
			f[i][j][0][0]=(
				 1ll*f[i-1][j][0][0]*C2(p+1)%mod
				+1ll*f[i-1][j][0][1]*C2(x[i]+1)%mod
				+1ll*f[i-1][j][1][0]*C2(p)%mod
				+1ll*f[i-1][j][1][1]*(1ll*x[i]*(p*2-x[i]-1)/2%mod)%mod
			)%mod;
			
			f[i][j][0][1]=(
				 1ll*(x[i]+1)*f[i-1][j][0][1]%mod
				+1ll*(p-x[i]-1)*f[i-1][j][1][1]%mod 
			)%mod;
			
			f[i][j+1][1][0]=(
				 1ll*f[i-1][j][0][0]*C2(p)%mod
				+1ll*f[i-1][j][0][1]*C2(x[i])%mod
				+1ll*f[i-1][j][1][0]*C2(p+1)%mod
				+1ll*f[i-1][j][1][1]*(1ll*x[i]*(p*2-x[i]+1)/2%mod)%mod
			)%mod;
			
			f[i][j+1][1][1]=(
				 1ll*(x[i])*f[i-1][j][0][1]%mod
				+1ll*(p-x[i])*f[i-1][j][1][1]%mod 
			)%mod;
//			cout<<i<<' '<<j<<' '<<f[i][j][0][0]<<' '<<f[i][j][0][1]<<' '<<f[i][j][1][0]<<' '<<f[i][j][1][1]<<endl;
		} 
	} 
	long long res=0;
	For(i,alpha,n)res=(res+f[n][i][0][0]+f[n][i][0][1])%mod;
	cout<<res;
	return 0;
}
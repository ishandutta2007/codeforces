#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=998244353;
inline int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}
int fac[5010],ifac[5010];
int S[5010][5010];
int f[5010];

int n;
int work(int k){
	int res=0;
	for (int j=k-1;j<n;j++){
		res=upd((res+(j-k+1&1?-1LL:1LL)*fac[j]*ifac[j-k+1]%Mod*f[j])%Mod);
	}
	res=1LL*res*fac[n]%Mod*ifac[k-1]%Mod;
	return res;
}
int main()
{
	n=read();
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n]=qpow(fac[n],Mod-2); for (int i=n;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	S[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			S[i][j]=(S[i-1][j-1]+1LL*j*S[i-1][j])%Mod;
	for (int j=0;j<n;j++)
		for (int i=j+1;i<=n;i++)
			f[j]=(f[j]+1LL*ifac[i]*S[i][i-j]%Mod*fac[i-j])%Mod;
	for (int i=1;i<=n;i++) printf("%d%c",work(i)," \n"[i==n]);
	return 0;
}
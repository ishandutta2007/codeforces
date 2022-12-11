#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
int fac[1000010],ifac[1000010];
int f[1000010],g[1000010];
int C(int n,int m)  //n>=m
{
	return 1LL*fac[n]*ifac[n-m]%Mod*ifac[m]%Mod;
}

int n,tot; char s[1000010];
int main()
{
	int a=0,b=0,c,d=0;
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) tot+=(s[i]=='?'),d+=(s[i]==')'); c=tot;
	
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n]=qpow(fac[n],Mod-2); for (int i=n;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	f[0]=1; for (int i=1;i<=tot;i++) f[i]=(f[i-1]+C(tot,i))%Mod;
	g[0]=1; for (int i=1;i<tot;i++) g[i]=(g[i-1]+C(tot-1,i))%Mod;
	
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]==')') d--;
		else if (s[i]=='?') c--;
		if (s[i]!=')'&&d+c-b-1>=0)
			ans=(ans+(a+c==tot?f[min(tot,d+c-b-1)]:g[min(tot-1,d+c-b-1)]))%Mod;
		if (s[i]=='(') b++;
		else if (s[i]=='?') a++;
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}
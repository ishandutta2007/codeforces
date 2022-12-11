#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
const int Mod=1e9+7;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int R,p1,p2,p3,p4,p,ip1,ip2,ip3,ip4,ip;
bool vis[110][110];
int w[110][110][110];
int a[110][110],b[110];
void Gauss(int n)
{
	for (int i=1;i<=n;i++)
	{
		int maxpos=-1;
		for (int j=i;j<=n;j++) if (a[j][i]){maxpos=j;break;}
		if (!~maxpos) puts("ERR: no solution");
		if (i^maxpos){for (int j=i;j<=n;j++) swap(a[i][j],a[maxpos][j]); swap(b[i],b[maxpos]);}
		int t=qpow(a[i][i],Mod-2); for (int j=i;j<=n;j++) a[i][j]=1LL*a[i][j]*t%Mod; b[i]=1LL*b[i]*t%Mod;
		for (int j=1;j<=n;j++)
		{
			if (j==i||!a[j][i]) continue;
			int s=a[j][i];
			for (int u=1;u<=n;u++) a[j][u]=(a[j][u]-1LL*a[i][u]*s)%Mod;
			b[j]=(b[j]-1LL*b[i]*s)%Mod;
		}
	}
}
int main()
{
	R=read(),p1=read(),p2=read(),p3=read(),p4=read(),p=p1+p2+p3+p4;
	ip1=qpow(p1,Mod-2); ip2=qpow(p2,Mod-2); ip3=qpow(p3,Mod-2); ip4=qpow(p4,Mod-2); ip=qpow(p,Mod-2);
	for (int i=1;i<=(R<<1|1);i++)  //+=R+1
		for (int j=1;j<=(R<<1|1);j++)
			if ((i-R-1)*(i-R-1)+(j-R-1)*(j-R-1)<=R*R)
			{
				vis[i][j]=1;
				if (vis[i-1][j]){
					for (int u=0;u<=(R<<1|1);u++)
						w[i][j][u]=(w[i-1][j][u]-1LL*p1*ip%Mod*w[i-2][j][u]-1LL*p2*ip%Mod*w[i-1][j-1][u]-1LL*p4*ip%Mod*w[i-1][j+1][u])%Mod;
					w[i][j][0]=(w[i][j][0]-1)%Mod;
					for (int u=0;u<=(R<<1|1);u++) w[i][j][u]=1LL*w[i][j][u]*ip3%Mod*p%Mod;
				}
				else{
					w[i][j][j]=1;
				}
			}
	for (int i=1;i<=(R<<1|1);i++)  //+=R+1
		for (int j=1;j<=(R<<1|1);j++)
			if (vis[i][j]&&!vis[i+1][j])
			{
				for (int u=0;u<=(R<<1|1);u++)
					a[j][u]=(w[i][j][u]-1LL*p1*ip%Mod*w[i-1][j][u]-1LL*p2*ip%Mod*w[i][j-1][u]-1LL*p4*ip%Mod*w[i][j+1][u])%Mod;
				a[j][0]=(a[j][0]-1)%Mod; b[j]=-a[j][0];
			}
	Gauss(R<<1|1);
	int ans=w[R+1][R+1][0];
	for (int i=1;i<=(R<<1|1);i++) ans=(ans+1LL*b[i]*w[R+1][R+1][i])%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}
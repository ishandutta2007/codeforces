#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
int mod;
typedef long long ll;
inline int upd(int x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}

int n,m;
int f[512][512],g[512][512];
int p[512],q[512];
int C[512][512];
int main()
{
	n=read(),m=read(),mod=read();
	
	for (int i=0;i<=n;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=upd(C[i-1][j]+C[i-1][j-1]-mod);
	}
	
	p[0]=1,q[0]=0;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=i;j++){
			add(p[i],1LL*p[j-1]*p[i-j]%mod*C[i-1][j-1]%mod);
		}
		p[i]=1LL*p[i]*(i+1)%mod;
		for (int j=1;j<=i;j++){
			add(q[i],(1LL*q[j-1]*p[i-j]+1LL*p[j-1]*q[i-j])%mod*C[i-1][j-1]%mod*(i+1)%mod);
			add(q[i],1LL*p[j-1]*p[i-j]%mod*C[i-1][j-1]%mod*(C[j][2]+C[i-j+1][2])%mod);
		}
	}
	
	for (int i=0;i<=n;i++) f[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m&&j<=i;j++){
			if (i==j){f[i][j]=p[i],g[i][j]=q[i];continue;}
			add(f[i][j],f[i-1][j]);
			add(g[i][j],g[i-1][j]);
			for (int k=1;k<i&&k<=j;k++)
				add(f[i][j],1LL*C[j][k]*f[i-1-k][j-k]%mod*p[k]%mod),
				add(g[i][j],(1LL*g[i-1-k][j-k]*p[k]+1LL*f[i-1-k][j-k]*q[k])%mod*C[j][k]%mod);
		}
	
	/*for (int i=0;i<=n;i++)
		for (int j=0;j<=i&&j<=m;j++)
			printf("%d %d: %d %d\n",i,j,f[i][j],g[i][j]);*/
	
	printf("%d\n",g[n][m]);
	return 0;
}
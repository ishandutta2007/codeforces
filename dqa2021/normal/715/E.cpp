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
const int Mod=998244353;

int n,p[256],q[256]; int ringtot,btot,ctot,dtot;
bool in[256],out[256]; int pre[256],nxt[256];
bool vis[256];
int C[256][256],A[256][256],S[256][256];
int f[256],g[256],h[256],s[256],t[256];
int main()
{
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++){
		q[i]=read();
		if (p[i]&&q[i]) in[q[i]]=out[p[i]]=1,pre[q[i]]=p[i],nxt[p[i]]=q[i];
		else if (p[i]&&!q[i]) out[p[i]]=1;
		else if (!p[i]&&q[i]) in[q[i]]=1;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		int j=i; vis[j]=1; for (;pre[j]&&!vis[pre[j]];j=pre[j],vis[j]=1);
		if (pre[j]&&vis[pre[j]]){ringtot++; continue;}
		int u=j; j=i; vis[j]=1; for (;nxt[j];j=nxt[j],vis[j]=1); int v=j;
		if (!in[u]&&!out[v]) dtot++;
		else if (in[u]&&!out[v]) btot++;
		else if (!in[u]&&out[v]) ctot++;
	}
	C[0][0]=A[0][0]=S[0][0]=1;
	for (int i=1;i<=n;i++){
		C[i][0]=A[i][0]=1; S[i][0]=0;
		for (int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
			A[i][j]=1LL*A[i-1][j-1]*i%Mod;
			S[i][j]=(S[i-1][j-1]+(i-1LL)*S[i-1][j])%Mod;
		}
	}
	if (!dtot){
		for (int i=0;i<=btot;i++) f[i]=S[btot][i];
		for (int i=0;i<=ctot;i++) g[i]=S[ctot][i];
		h[0]=1;
	}
	else{
		for (int i=0;i<=btot;i++)
			for (int j=i;j<=btot;j++)
				f[i]=(f[i]+1LL*C[btot][j]*S[j][i]%Mod*A[btot-j-1+dtot][btot-j])%Mod;
		for (int i=0;i<=ctot;i++)
			for (int j=i;j<=ctot;j++)
				g[i]=(g[i]+1LL*C[ctot][j]*S[j][i]%Mod*A[ctot-j-1+dtot][ctot-j])%Mod;
		int fac=1; for (int i=1;i<=dtot;i++) fac=1LL*fac*i%Mod;
		for (int i=0;i<=dtot;i++) h[i]=1LL*S[dtot][i]*fac%Mod;
	}
	for (int i=0;i<=btot;i++)
		for (int j=0;j<=ctot;j++)
			s[i+j]=(s[i+j]+1LL*f[i]*g[j])%Mod;
	for (int i=0;i<=btot+ctot;i++)
		for (int j=0;j<=dtot;j++)
			t[i+j]=(t[i+j]+1LL*s[i]*h[j])%Mod;
	for (int i=0;i<n;i++) printf("%d%c",n-i<ringtot?0:(t[n-i-ringtot]+Mod)%Mod," \n"[i==n-1]);
	return 0;
}
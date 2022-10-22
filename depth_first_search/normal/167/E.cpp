#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 600
#define M 100000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,X,A[N+5],B[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[M+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int a[N+5][N+5];I int Det(CI n)
{
	RI i,j,k,t,s=1;for(i=1;i<=n;s=1LL*s*a[i][i]%X,++i)
	{
		if(!a[i][i]) {for(s=X-s,j=i+1;j<=n&&!a[j][i];++j);for(k=i;k<=n;++k) swap(a[i][k],a[j][k]);}
		for(j=i+1;j<=n;++j) for(t=1LL*(X-a[j][i])*QP(a[i][i],X-2)%X,k=i;k<=n;++k) a[j][k]=(a[j][k]+1LL*t*a[i][k])%X;
	}return s;
}
int d[N+5],q[N+5],f[N+5];I void Topo()
{
	RI i,H=1,T=0;for(i=1;i<=n;++i) !d[i]&&(q[++T]=i);
	W(H<=T) for(i=lnk[q[H++]];i;i=e[i].nxt) !--d[e[i].to]&&(q[++T]=e[i].to);
	RI j,k;for(i=1;i<=n;++i) if(A[i])
	{
		for(j=1;j<=n;++j) f[j]=0;f[i]=1;
		for(j=1;j<=n;++j) for(k=lnk[q[j]];k;k=e[k].nxt) f[e[k].to]=(f[e[k].to]+f[q[j]])%X;
		for(j=1;j<=n;++j) B[j]&&(a[A[i]][B[j]]=f[j]);
	}
}
int main()
{
	RI i,x,y,t;for(scanf("%d%d%d",&n,&m,&X),i=1;i<=n;++i) A[i]=B[i]=1;
	for(i=1;i<=m;++i) scanf("%d%d",&x,&y),add(x,y),++d[y],B[x]=A[y]=0;
	for(t=0,i=1;i<=n;++i) A[i]&&(A[i]=++t);for(t=0,i=1;i<=n;++i) B[i]&&(B[i]=++t);
	return Topo(),printf("%d\n",Det(t)),0;
}
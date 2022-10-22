#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2000
#define X 998244353
using namespace std;
int n,m,tot,pw[N*N+5];char s[N+5][N+5];
I void Solve0()
{
	RI i,j;if(!(m&1)) {for(i=1;i<=n;++i) for(j=1;j<=m;++j) i<j&&(swap(s[i][j],s[j][i]),0);swap(n,m);}
	RI o,f0=1,f1=1;for(i=1;i<=n;++i) {for(o=0,j=1;j<=m&&s[i][j]^'?';++j) o^=s[i][j]&1;j>m?(o?f0:f1)=0:--tot;}
	printf("%d\n",pw[tot]*(f0+f1)%X);
}
int HA=1,TA=0,HB=1,TB=0,vA[N+5],vB[N+5],qA[N+5],qB[N+5],dA[N+5],dB[N+5];
I void DA(CI x) {for(RI i=1;i<=m;++i) !dB[i]&&s[x][i]=='?'&&(dB[qB[++TB]=i]=1);}
I void DB(CI x) {for(RI i=1;i<=n;++i) !dA[i]&&s[i][x]=='?'&&(dA[qA[++TA]=i]=1);}
int main()
{
	RI i,j;for(scanf("%d%d",&n,&m),pw[0]=i=1;i<=n*m;++i) pw[i]=(pw[i-1]<<1)%X;
	for(i=1;i<=n;++i) for(scanf("%s",s[i]+1),j=1;j<=m;++j) s[i][j]=='?'&&++tot;
	if(!(n&1)&&!(m&1)) return printf("%d\n",pw[tot]),0;if(!(n&1)||!(m&1)) return Solve0(),0;
	for(tot-=n+m,i=1;i<=n;++i) for(j=1;j<=m;++j) s[i][j]^'?'&&(vA[i]^=s[i][j]&1,vB[j]^=s[i][j]&1);
	RI x,y,t0,t1,f0=1,f1=1;W(true)
	{
		for(x=y=t0=t1=0,i=1;i<=n;++i) !dA[i]&&(t0^=vA[i],t1^=vA[i]^1,x=i);
		for(i=1;i<=m;++i) !dB[i]&&(t0^=vB[i],t1^=vB[i]^1,y=i);
		if(!x&&!y) break;t0&&(f0=0),t1&&(f1=0),++tot,x?dA[qA[++TA]=x]=1:dB[qB[++TB]=y]=1;
		W(HA<=TA||HB<=TB) HA<=TA?DA(qA[HA++]):DB(qB[HB++]);
	}return printf("%d\n",pw[tot]*(f0+f1)%X),0;
}
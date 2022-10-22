#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define M 10
#define mp make_pair
using namespace std;
int n,m,sz,bl[N+5];char s[N+1][M+1];
pair<int,int> g[N+1][M+1];I void Bd(CI L,CI R)
{
	RI i,j,k;for(i=L;i<=R;++i)
	{
		for(j=1;j<=m;++j) s[i][j]=='^'&&(g[i][j]=i^L?g[i-1][j]:mp(i-1,j),0);
		for(k=-1,j=1;j<=m;++j) s[i][j]=='<'?(g[i][j]=~k?(s[i][k]=='^'?g[i][k]:mp(-1,-1)):mp(i,0),0):k=j;
		for(k=-1,j=m;j>=1;--j) s[i][j]=='>'?(g[i][j]=~k?(s[i][k]=='^'?g[i][k]:mp(-1,-1)):mp(i,m+1),0):k=j;
	}
}
I void Q(RI x,RI y)
{
	pair<int,int> t;W(true) if(t=g[x][y],x=t.first,y=t.second,x<1||y<1||y>m) {printf("%d %d\n",t.first,t.second);return;}
}
int main()
{
	RI Qt,i,j;for(scanf("%d%d%d",&n,&m,&Qt),sz=sqrt(n),i=1;i<=n;++i) scanf("%s",s[i]+1),bl[i]=(i-1)/sz+1;
	for(i=1;i<=bl[n];++i) Bd((i-1)*sz+1,min(i*sz,n));
	char op;RI x,y;W(Qt--) cin>>op,scanf("%d%d",&x,&y),op=='A'?Q(x,y):(cin>>s[x][y],Bd((bl[x]-1)*sz+1,min(bl[x]*sz,n)));return 0;
}
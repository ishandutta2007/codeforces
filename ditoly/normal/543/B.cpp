#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 3000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,d[MN+5][MN+5],q[MN+5],qn;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
int main()
{
	int n=read(),m=read(),i,j,k,s1,t1,l1,s2,t2,l2,ans;
	for(i=1;i<=m;++i)ins(read(),read());
	for(i=1;i<=n;++i)for(d[i][q[j=qn=1]=i]=1;j<=qn;++j)
		for(k=h[q[j]];k;k=e[k].nx)if(!d[i][e[k].t])d[i][q[++qn]=e[k].t]=d[i][q[j]]+1;
	s1=read();t1=read();l1=read();
	s2=read();t2=read();l2=read();
	ans=d[s1][t1]-1<=l1&&d[s2][t2]-1<=l2?d[s1][t1]+d[s2][t2]-2:m+1;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)
		if(min(d[s1][i]+d[j][t1],d[s1][j]+d[i][t1])+d[i][j]-3<=l1&&
		   min(d[s2][i]+d[j][t2],d[s2][j]+d[i][t2])+d[i][j]-3<=l2)
			ans=min(ans,min(d[s1][i]+d[j][t1],d[s1][j]+d[i][t1])+
						min(d[s2][i]+d[j][t2],d[s2][j]+d[i][t2])+d[i][j]-5);
	printf("%d",m-ans);
}
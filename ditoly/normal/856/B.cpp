#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 1000000
char s[MN+5];
int c[MN+5][26],tn,h[MN+5],en,u[MN+5],f[MN+5][2];
struct edge{int nx,t;}e[MN+5];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void dfs(int x,int f)
{
	if(f>0)ins(f,x),u[x]=1;
	for(int i=0;i<26;++i)if(c[x][i]&&c[f][i])dfs(c[x][i],c[f][i]);
}
void dp(int x)
{
	f[x][1]=1;f[x][0]=0;
	for(int i=h[x];i;i=e[i].nx)
	{
		dp(e[i].t);
		f[x][0]+=max(f[e[i].t][0],f[e[i].t][1]);
		f[x][1]+=f[e[i].t][0];
	}
}
int main()
{
	int T,n,i,j,ans;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		while(n--)for(scanf("%s",s),i=j=0;s[i];++i)
			s[i]-='a',j=c[j][s[i]]?c[j][s[i]]:c[j][s[i]]=++tn;
		for(i=0;i<26;++i)if(c[0][i])dfs(c[0][i],0);
		for(ans=0,i=1;i<=tn;++i)if(!u[i])dp(i),ans+=max(f[i][0],f[i][1]);
		printf("%d\n",ans);
		for(i=0;i<=tn;++i)memset(c[i],0,sizeof(c[i])),h[i]=u[i]=0;tn=en=0;
	}
}
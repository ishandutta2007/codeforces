#include<cstdio>
#include<cstring>
#define MAX 1000
#define MAXV 1000000
#define MAXE 4000000
const int o[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[MAX+5][MAX+5];
struct edge{int nx,t;}e[MAXE+5];
int h[MAXV+5],en,f[3][MAXV+5],cnt,q[MAXV+5],qn;
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void dfs(int x,int y)
{
	int l,i,j;s[x][y]=cnt;
	for(l=0;l<4;l++)
	{
		i=x+o[l][0];j=y+o[l][1];
		if(i<0||j<0||s[i][j]<'1'||s[i][j]>'3')continue;
		dfs(i,j);
	}
}
int main()
{
	int n,m,l,i,j,x,y,p,ans=-1;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(s[i][j]>'0'&&s[i][j]<'4')dfs(i,j),cnt++;
	if(cnt<2)return 0*puts("0");
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(s[i][j]!='#')for(l=0;l<4;l++)
	{
		x=i+o[l][0];y=j+o[l][1];
		if(x<0||y<0||x==n||y==m||s[x][y]=='#')continue;
		if(s[x][y]=='.')ins(s[i][j]=='.'?i*m+j:s[i][j]+MAXV,x*m+y);
		else if(s[i][j]=='.')ins(i*m+j,s[x][y]+MAXV);
	}
	for(l=0;l<cnt;l++)
		for(f[l][q[i=qn=0]=l+MAXV]=1;i<=qn;i++)for(j=h[q[i]];j;j=e[j].nx)
			if(!f[l][e[j].t])f[l][e[j].t]=f[l][q[i]]+1,q[++qn]=e[j].t;
	for(i=0;i<MAXV+3;i++)
	{
		for(j=0;j<cnt;j++)if(!f[j][i])break;
		if(j<cnt)continue;
		p=i<MAXV?1-cnt:1;
		for(j=p=0;j<cnt;j++)p+=f[j][i]-2;
		if(p+1<ans||ans<0)ans=p+1;
	}
	printf("%d",ans);
}
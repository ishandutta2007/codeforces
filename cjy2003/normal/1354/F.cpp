#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int upmax(int &x,int y){return x<y?x=y,1:0;}
struct minion
{
	int a,b,id;
	friend bool operator < (minion a,minion b){return a.b<b.b;}
}p[100];
int T,n,m,dp[100][100][100],from[100][100][100];
bool in[100];
void getans(int i,int j,int k)
{
	if(!i)return;
	in[i]=from[i][j][k]==-1;
	if(from[i][j][k]==-1)getans(i-1,j-1,k);
	else getans(i-1,j,from[i][j][k]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d %d",&p[i].a,&p[i].b),p[i].id=i;
		sort(p+1,p+1+n);
		memset(dp,0xc0,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=1;i<=n;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<i;++k)
					if(dp[i-1][j][k]!=0xc0c0c0c0)
					{
						if(j<m)upmax(dp[i][j+1][k],dp[i-1][j][k]+p[i].b*j+p[i].a)?from[i][j+1][k]=-1:0;
						if(p[i].a>p[k].a)upmax(dp[i][j][i],dp[i-1][j][k]+p[i].b*(m-1))?from[i][j][i]=k:0;
						else upmax(dp[i][j][k],dp[i-1][j][k]+p[i].b*(m-1))?from[i][j][k]=k:0;
					}
		int mx=0,x;
		for(int i=1;i<=n;++i)upmax(mx,dp[n][m-1][i]+p[i].a)?x=i:0;
		getans(n,m-1,x);
		printf("%d\n",n+(n-m));
		for(int i=1;i<=n;++i)if(in[i])printf("%d ",p[i].id);
		for(int i=1;i<=n;++i)if(!in[i]&&i!=x)printf("%d %d ",p[i].id,-p[i].id);
		printf("%d\n",p[x].id);
	}
	return 0;
}
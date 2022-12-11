#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,b[1010][3],d[1010],rt,lf[1010];
int ans[100010][3],m;
vector<pair<int,int> >E[1010];
void makeans(int x,int y,int w){if(w)ans[++m][0]=x,ans[m][1]=y,ans[m][2]=w;}
void dfs(int v,int fa,int w)
{
	if(d[v]==1&&fa)
	{
		makeans(rt,v,w);
		lf[v]=v;
		return ;
	}
	int lf1=0,lf2=0,sum=w;
	for(auto u:E[v])
	{
		if(u.first==fa)continue;
		dfs(u.first,v,u.second);sum-=u.second;
		if(!lf1)lf1=lf[u.first];
		else if(!lf2)lf2=lf[u.first];
	}
	if(v==rt)return ;
//	printf("%d %d %d\n",v,lf1,lf2);
	makeans(lf1,lf2,-sum/2);
	makeans(lf1,rt,sum/2);
	makeans(lf2,rt,sum/2);
	lf[v]=lf1;
}
int main()
{
	scanf("%d",&n);
	int x,y,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		E[x].push_back(make_pair(y,w));
		E[y].push_back(make_pair(x,w));
		++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)
		if(d[i]==2)
		{
			printf("NO");
			return 0;
		}
	for(int i=1;i<=n;++i)
		if(d[i]==1)
		{
			rt=i;
			break;
		}
	dfs(rt,0,0);
	printf("YES\n");
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}
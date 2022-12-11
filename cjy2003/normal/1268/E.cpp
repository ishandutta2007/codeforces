#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> >E[500050];
vector<int>cir[500050];
int n,m,dep[500050],f[500050],fb[500050],ans[500050],b[500050][2],s[500050];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;f[v]=fa;
	for(auto u:E[v])
	{
		if(!dep[u.first])fb[u.first]=u.second,dfs(u.first,v);
		else if(dep[v]<dep[u.first])
		{
			int x=u.first,mi=u.second,p=0;
			while(x!=v)
			{
				if(fb[x]<mi)mi=fb[x],p=x;
				x=f[x];
			}
			if(!p)
			{
				x=u.first;
				while(x!=v)cir[mi].emplace_back(fb[x]),x=f[x];
			}
			else
			{
				x=f[p];
				while(x!=v)cir[mi].emplace_back(fb[x]),x=f[x];
				cir[mi].emplace_back(u.second);
				x=u.first;
				while(x!=p)cir[mi].emplace_back(fb[x]),x=f[x];
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		E[x].emplace_back(make_pair(y,i));
		E[y].emplace_back(make_pair(x,i));
		b[i][0]=x,b[i][1]=y;
	}
	dfs(1,0);
/*	for(int i=1;i<=m;++i)
	{
		for(auto u:cir[i])printf("%d ",u);
		printf("\n");
	}*/
	for(int i=1;i<=n;++i)ans[i]=1;
	for(int i=m;i;--i)
	{
	//	printf("%d\n",i);
		ans[b[i][0]]=ans[b[i][1]]=ans[b[i][0]]+ans[b[i][1]];
		if(cir[i].size())
		{
			int p1=0,p2=cir[i].size()-1;
		//	printf("%d %d %u\n",p1,p2,cir[i].size()-1);
			while(p1<cir[i].size()-1&&cir[i][p1]<cir[i][p1+1])++p1;
		//	printf("%d\n",p1);
			while(p2>0&&cir[i][p2]<cir[i][p2-1])--p2;
		//	printf("%d\n",i);
		//	printf("%d %d\n",p1,p2);
			if(p1==p2)ans[b[i][0]]=ans[b[i][1]]=ans[b[i][0]]-s[cir[i][p1]];	
		}
		s[i]=ans[b[i][0]];
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]-1);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=998244353,E=262144;
int n,x,las[N],d[N],md,ans[N],i,u;
bitset<100001> f,ff,tmp;
vector<int> g[N];
vector<int> p[2][N];
void dfs(int i,int d)
{
	md=max(md,d);
	p[g[i].size()==0][d].push_back(i);
	for(auto it:g[i])
		dfs(it,d+1);
}
int main()
{
	scanf("%d %d",&n,&x);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&u);
		g[u].push_back(i);
	}
	dfs(1,1);
	f[0]=1;
	for(i=1;i<=md;++i)
	{
		ff=f|f<<p[0][i].size()+p[1][i].size();
		tmp=f^ff;
		f=ff;
		for(int j=tmp._Find_first();j!=tmp.size();j=tmp._Find_next(j)) 
		{
			las[j]=j-p[0][i].size()-p[1][i].size();
			d[j]=i;
		}
	}
	if(!f[x])
	{
		printf("%d\n",md+1);
		int s=0;
		for(i=1;i<=md;++i)
			if(s+p[0][i].size()+p[1][i].size()<x)
			{
				for(auto j:p[0][i])
					ans[j]=1;
				for(auto j:p[1][i])
					ans[j]=1;
				s+=p[0][i].size()+p[1][i].size();
			}
			else
				if(s+p[0][i].size()<=x)
				{
					for(auto j:p[0][i])
						ans[j]=1;
					for(int j=0;j<x-s-p[0][i].size();++j)
						ans[p[1][i][j]]=1;
					break;
				}
	}
	else
	{
		printf("%d\n",md);
		for(i=x;i;i=las[i])
		{
			for(auto it:p[0][d[i]])
				ans[it]=1;
			for(auto it:p[1][d[i]])
				ans[it]=1;
		}
	}
	for(i=1;i<=n;++i)
		putchar(ans[i]?'a':'b');
}
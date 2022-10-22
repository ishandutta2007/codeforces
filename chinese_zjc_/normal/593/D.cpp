//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
vector <pair<int,int> > son[200005];
int fa[200005],fat[200005],p[200005],v[200005],depth[200005],n,m,f,t,tmp;
void dfs(int now)
{
	fat[now]=now;
	for(int i=0;i<(int)son[now].size();++i)
	{
		if(son[now][i].second==fa[now])
		{
			swap(son[now][i],son[now][son[now].size()-1]);
			son[now].pop_back();
			--i;
			continue;
		}
		fa[son[now][i].second]=now;
		depth[son[now][i].second]=depth[now]+1;
		p[son[now][i].second]=son[now][i].first;
		dfs(son[now][i].second);
	}
}
int find(int now)
{
	return fat[now]==now?now:fat[now]=find(fat[now]);
}
int work(int l,int r,int V)
{
	while(l!=r&&V)
	{
		if(depth[l]<depth[r])
		{
			V/=v[p[r]];
			if(v[p[r]]==1)
			{
				fat[r]=fa[r];
			}
			r=find(fa[r]);
		}
		else
		{
			V/=v[p[l]];
			if(v[p[l]]==1)
			{
				fat[l]=fa[l];
			}
			l=find(fa[l]);
		}
	}
	return V;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;++i)
	{
		cin>>f>>t>>v[i];
		son[f].push_back(make_pair(i,t));
		son[t].push_back(make_pair(i,f));
	}
	dfs(1);
	for(int i=1;i<=m;++i)
	{
		cin>>tmp;
		if(tmp==1)
		{
			cin>>f>>t>>tmp;
			cout<<work(find(f),find(t),tmp)<<endl;
		}
		else
		{
			cin>>f>>t;
			v[f]=t;
		}
	}
	return 0;
}
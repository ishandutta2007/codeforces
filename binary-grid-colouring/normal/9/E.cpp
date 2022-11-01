#include <bits/stdc++.h>
using namespace std;
int fa[55];
int e1[2510],e2[2510];
int degree[55];
vector<pair<int,int>>ans;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void Union(int x,int y)
{
	int p1=find(x);
	int p2=find(y);
	if(p1!=p2){
		fa[p2]=p1;
	}
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e1[i]>>e2[i];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		Union(e1[i],e2[i]);
		degree[e1[i]]++; 
		degree[e2[i]]++;
		if(degree[e1[i]]>2 || degree[e2[i]]>2)
		return 0*printf("NO");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(degree[i]<=1 && degree[j]<=1  && find(i)!=find(j))
			{
				ans.push_back(make_pair(j,i));
				Union(i,j);
				degree[i]++;
				degree[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(degree[i]==2)continue;
		for(int j=1;j<i;j++)
		{
			if(degree[j]==1)
			{
				ans.push_back(make_pair(j,i));
				Union(i,j);
				degree[i]++;
				degree[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(degree[i]==0){
			ans.push_back(make_pair(i,i));
		}
	}
	
	int p = find(1);
	for(int i=1;i<=n;i++)
	{
		if(find(i)!=p) return 0*printf("NO");
	}
	puts("YES");
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
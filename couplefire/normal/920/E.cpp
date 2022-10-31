#include<bits/stdc++.h>
using namespace std;
set<int>s[200005],ss;
vector<int>v;
set<int> :: iterator it;
int dfs(int node)
{
	int siz=1;
	for(it=ss.begin();it!=ss.end();)
	{
		int i=(*it);
		if(!s[node].count(i))
		{
			ss.erase(i);
			siz+=dfs(i);
			it=ss.lower_bound(i);
		}
		else it++;
	}
	return siz;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		s[x].insert(y);
		s[y].insert(x);
	}
	for(int i=1;i<=n;i++)ss.insert(i);
	for(int i=1;i<=n;i++)
	{
		if(ss.count(i))
		{
			ss.erase(i);
			v.push_back(dfs(i));
		}
	}
	cout<<v.size()<<"\n";
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	return 0;
}
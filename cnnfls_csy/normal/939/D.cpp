#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,vis[35];
vector<pair<char,char>/**/> ans;
vector<int> bi[35];
string st,st2;
void dfs(int x)
{
	int i;
	vis[x]=1;
	for (i=0;i<bi[x].size();i++)
	{
		if (!vis[bi[x][i]])
		{
			ans.push_back(make_pair(bi[x][i]+'a',x+'a'));
			dfs(bi[x][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>st>>st2;
	for (i=0;i<st.length();i++)
	{
		bi[st[i]-'a'].push_back(st2[i]-'a');
		bi[st2[i]-'a'].push_back(st[i]-'a');
	}
	for (i=0;i<=25;i++)
	{
		if (vis[i]) continue;
		dfs(i);
	}
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}
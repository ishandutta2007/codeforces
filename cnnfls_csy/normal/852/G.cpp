#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
map<string,int> mp;
set<string> used;
string st;
int n,m,i,j,ans,now[15];
vector<int> pos;
void get()
{
	int del=0,i;
	string st1;
	st1=st;
	for (i=0;i<pos.size();i++)
	{
		if (now[i]==-1)
		{
			st1.erase(pos[i]-del,1);
			del++;
		}
		else st1[pos[i]-del]=now[i];
	}
	used.insert(st1);
}
void dfs(int x)
{
	if (x>=pos.size())
	{
		get();
		return;
	}
	int i;
	now[x]=-1;
	dfs(x+1);
	for (i='a';i<='e';i++)
	{
		now[x]=i;
		dfs(x+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		mp[st]++;
	}
	for (i=1;i<=m;i++)
	{
		cin>>st;
		pos.clear();
		for (j=0;j<st.length();j++)
		{
			if (st[j]=='?')
			{
				pos.push_back(j);
			}
		}
		used.clear();
		dfs(0);
		ans=0;
		for (set<string>::iterator it=used.begin();it!=used.end();it++) if (mp.count(*it)) ans+=mp[*it];
		cout<<ans<<endl;
	}
	return 0;
}
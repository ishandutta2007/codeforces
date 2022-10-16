#include<bits/stdc++.h>
using namespace std;
int n,a[102],b[102];
bool vis1[102],vis2[102];
vector<int>v[102];
vector<int>dfs1(int i)
{
	vis1[i]=1;
	vector<int>res;
	res.push_back(a[i]);
	for(int j=0;j<v[i].size();j++)
		if(!vis1[v[i][j]])
		{
			vector<int>res2=dfs1(v[i][j]);
			for(int k=0;k<res2.size();k++)
				res.push_back(res2[k]);
		}
	return res;
}
vector<int>dfs2(int i)
{
	vis2[i]=1;
	vector<int>res;
	res.push_back(i);
	for(int j=0;j<v[i].size();j++)
		if(!vis2[v[i][j]])
		{
			vector<int>res2=dfs2(v[i][j]);
			for(int k=0;k<res2.size();k++)
				res.push_back(res2[k]);
		}
	return res;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],a[i]--;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		if(b[i]+i<n)
			v[i].push_back(b[i]+i),
			v[b[i]+i].push_back(i);
		if(i-b[i]>-1)
			v[i-b[i]].push_back(i),
			v[i].push_back(i-b[i]);
	}
	for(int i=0;i<n;i++)
		if(!vis1[i])
		{
			vector<int>v1=dfs1(i);
			vector<int>v2=dfs2(i);
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());
			if(v1!=v2)
			{
				cout<<"NO";
				return 0;
			}
		}
	cout<<"YES";
}
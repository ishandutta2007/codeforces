#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#include<queue>
using namespace std;
int co[1005],n,m,i,j,x,y,z,ma;
vector<pair<int,int>/**/> bi[1005];
bool used[1005];
int bfs()
{
	int s=0,i;
	queue<int> q;
	used[0]=1;
	q.push(0);
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		for (i=0;i<bi[x].size();i++)
		{
			if (used[bi[x][i].first]) continue;
			q.push(bi[x][i].first);
			co[bi[x][i].first]=co[x]+bi[x][i].second;
			s=max(s,co[bi[x][i].first]);
			used[bi[x][i].first]=1;
		}
	}
	return s;
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		bi[x].push_back(make_pair(y,z));
		bi[y].push_back(make_pair(x,z));
	}
	cout<<bfs();
	return 0;
}
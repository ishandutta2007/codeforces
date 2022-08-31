#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
vector<pair<long long,long long>/**/> bi[100005];
long long n,m,i,j,used[100005],dis[100005],pr[100005],x,y,z;
priority_queue<pair<long long,long long>/**/> q;
void print(int x)
{
	if (pr[x]) print(pr[x]);
	cout<<x<<' ';
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		bi[x].push_back(make_pair(y,z));
		bi[y].push_back(make_pair(x,z));
	}
	for (i=2;i<=n;i++) dis[i]=1e15;
	q.push(make_pair(-0,1));
	while (!q.empty())
	{
		x=q.top().second;
		q.pop();
		if (used[x]) continue;
		used[x]=1;
		for (i=0;i<bi[x].size();i++)
		{
			if (dis[bi[x][i].first]>dis[x]+bi[x][i].second)
			{
				dis[bi[x][i].first]=dis[x]+bi[x][i].second;
				q.push(make_pair(-dis[bi[x][i].first],bi[x][i].first));
				pr[bi[x][i].first]=x;
			}
		}
	}
	if (dis[n]<1e14) print(n); else cout<<-1;
	return 0;
}
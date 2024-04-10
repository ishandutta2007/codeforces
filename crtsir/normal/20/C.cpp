#include<bits/stdc++.h>
using namespace std;
const long long INF=12345678987654321;
long long d[100010];
int n,m;
priority_queue<pair<long long,int> >q;
int p[100010];
vector<pair<int,int> >v[100010];
void dfs(int x)
{
	if(x>1)
		dfs(p[x]);
	cout<<x<<' ';
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)d[i]=INF;
	for(int i=1;i<=m;i++)
	{
		int a,b,len;
		cin>>a>>b>>len;
		v[a].push_back(make_pair(b,len));
		v[b].push_back(make_pair(a,len));
	}
	long long x,y;
	int b;
	d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		x=-q.top().first,b=q.top().second;
		//cout<<x;
		q.pop();
		if(x!=d[b])continue;
		for(vector<pair<int,int> >::const_iterator i=v[b].begin();i!=v[b].end();i++)
		{
			if((y=x+i->second)<d[i->first])
			{
				q.push(make_pair(-(d[i->first]=y),i->first));
				p[i->first]=b;
			}
		}
	}
	if(d[n]==INF)
		cout<<-1;
	else
		dfs(n);
}
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<long long,int> pii;

const long long INF = 1e18;

vector<vector<int> > g,w;
vector<long long> d;
vector<int> p,ans;
priority_queue<pii> q;
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	g.resize(n);
	w.resize(n);
	for (int i=0; i<m; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	d.resize(n,INF);
	p.resize(n);
	d[0]=0;
	p[0]=-1;
	q.push(pii(0,0));
	while (!q.empty())
	{
		int v=q.top().second;
		int cur_d=-q.top().first;
		q.pop();
		if (d[v]<cur_d)continue;
		for (int i=0; i<g[v].size(); i++)
		{
			int u=g[v][i];
			if (d[u]>d[v]+w[v][i])
			{
				d[u]=d[v]+w[v][i];
				p[u]=v;
				q.push(pii(-d[u],u));
			}
		}
	}
	if (d[n-1]==INF)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=n-1; i!=-1; i=p[i])
		ans.push_back(i);
	for (int i=ans.size()-1; i>=0; i--)
		printf("%d ",ans[i]+1);
	printf("\n");
	return 0;
}
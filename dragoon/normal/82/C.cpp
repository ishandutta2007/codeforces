#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int prio[5002];

struct SS
{
	int a,pa;
	SS(int x){a=x; pa = prio[x];}
};

bool operator<(SS A, SS B) { return A.pa > B.pa;}

queue<int> Q;
vector<int> X;
priority_queue<SS> PQ[5002];
int vis[5002];
typedef pair<int,int> PII;
vector<PII> V[5002];
int parent[5002],cap[5002];

void BFS()
{
	int at,sz,i,u;

	X.push_back(1);
	Q.push(1);
	while(!Q.empty())
	{
		at = Q.front();
		Q.pop();

		vis[at]=1;

		sz = V[at].size();
		for(i=0;i<sz;i++)
		{
			u = V[at][i].first;
			if(vis[u]) continue;

			Q.push(u);
			X.push_back(u);

			parent[u] = at;
			cap[u] = V[at][i].second;
		}
	}
}

int ans[5002];

int main()
{
	int n,i,cnt,sz,day;
	int a,b,c,u,ss,z;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&prio[i]);
	}

	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		V[a].push_back(PII(b,c));
		V[b].push_back(PII(a,c));
	}

	parent[1]=-1;
	BFS();

	for(i=2;i<=n;i++)
		PQ[i].push(SS(i));

	cnt=0;
	sz = X.size();
	day = 1;
	while(1)
	{
		for(i=1;i<sz;i++)
		{
			u = X[i];
			ss = 0;
			while(!PQ[u].empty() && ss<cap[u])
			{
				z = PQ[u].top().a; PQ[u].pop();
				if(parent[u]==1) {ans[z] = day; cnt++;}
				else PQ[parent[u]].push(SS(z));
				ss++;
			}
		}

		if(cnt==n-1)
			break;
		day++;
	}

	for(i=1;i<=n;i++)
	{
		if(i>1) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int in[N],n;
vector<int> v[N];

int main() 
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		in[x]++; in[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(in[i]==1) q.push(i);
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		if(q.empty())
		{
			printf("! %d\n",x);
			fflush(stdout);
			return 0;
		}
		int y=q.front(); q.pop();
		printf("? %d %d\n",x,y);
		fflush(stdout);
		int fa;
		scanf("%d",&fa);
		if(fa==x||fa==y)
		{
			printf("! %d\n",fa);
			fflush(stdout);
			return 0;
		}
		for(int i=0;i<(int)v[x].size();i++)
		{
			int to=v[x][i];
			in[to]--;
			if(in[to]==1) q.push(to);
		}
		for(int i=0;i<(int)v[y].size();i++)
		{
			int to=v[y][i];
			in[to]--;
			if(in[to]==1) q.push(to);
		}
	}
	return 0;
}
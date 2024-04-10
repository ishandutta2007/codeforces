#include<bits/stdc++.h>
using namespace std;
const int N=20001;

struct Edge{
	int from,to;
}E[N];
vector<int> v[N];
int n,m,in[N],c[N];

bool tuopu()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<(int)v[u].size();i++)
		{
			int p=v[u][i];
			in[p]--;
			if(!in[p]) q.push(p);
		}
	}
	int bl=0;
	for(int i=1;i<=n;i++) bl|=in[i];
	return bl;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&E[i].from,&E[i].to);
		v[E[i].from].push_back(E[i].to);
		in[E[i].to]++;
	}
	if(!tuopu())
	{
		puts("1");
		for(int i=1;i<=m;i++) printf("1 ");
	}
	else
	{
		puts("2");
		for(int i=1;i<=m;i++)
		{
			if(E[i].from<E[i].to) printf("1 ");
			else printf("2 ");
		}
	}
	return 0;
}
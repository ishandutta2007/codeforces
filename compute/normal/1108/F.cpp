#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
struct Edge{
	int u,v,w;
	bool operator< (const Edge &a) const{
		return w<a.w;
	}
}edge[maxn];
int far[maxn];
int n,m;
void init()
{
	for(int i=0;i<maxn;i++) far[i]=i;
}
int Find(int x)
{
	return x==far[x]?x:far[x]=Find(far[x]);
}
bool Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return false;
	far[y]=x;
	return true;
}
long long kruskal()
{
	long long ret=0;
	for(int i=0;i<m;i++)
	{
		int j=i;
		while(edge[j].w==edge[i].w) j++;
		int cnt=j-i;
		for(int k=i;k<j;k++)
		{
			if(Find(edge[k].u)==Find(edge[k].v)) cnt--;
		}
		for(int k=i;k<j;k++)
		{
			cnt-=Union(edge[k].u,edge[k].v);
		}
		ret+=cnt;
		i=j-1;
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	init();
	sort(edge,edge+m);
	printf("%lld\n",kruskal());
}
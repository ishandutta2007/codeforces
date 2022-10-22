#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int trie[6000001][2],cnt,n,a[200001],ID[6000001],tot;
vector<int> num[200001];
void insert(int v)
{
	int bj=0;
	for(int i=30;i>=0;--i)
	{
		int c=((v&(1<<i))>>i);
		if(!trie[bj][c])
			trie[bj][c]=++cnt;
		bj=trie[bj][c];
	}
}
int calc(int v,int u,int id)
{
	if(id==0)
		return 0;
	int c=((v&(1<<id-1))>>id-1);
	if(trie[u][c])
		return calc(v,trie[u][c],id-1);
	else
		return calc(v,trie[u][c^1],id-1)+(1<<id-1);
}
ll fun(int u,int id,int v)
{
	if(!id)
	{
		ID[u]=++tot;
		num[ID[u]].push_back(v);
		return 0;
	}
	if(!trie[u][0])
	{
		ll bck=fun(trie[u][1],id-1,v+(1<<id-1));
		ID[u]=ID[trie[u][1]];
		return bck;
	}
	if(!trie[u][1])
	{
		ll bck=fun(trie[u][0],id-1,v);
		ID[u]=ID[trie[u][0]];
		return bck;
	}
	ll bck=fun(trie[u][0],id-1,v)+fun(trie[u][1],id-1,v+(1<<id-1));
	int id0=ID[trie[u][0]],id1=ID[trie[u][1]],minn=2147483647;
	if(num[id0].size()<num[id1].size())
	{
		for(int i=0;i<num[id0].size();++i)
		{
			int v=num[id0][i];
			minn=min(minn,calc(v,trie[u][1],id-1));
			num[id1].push_back(v);
		}
		num[id0].clear();
		ID[u]=id1;
	}
	else
	{
		for(int i=0;i<num[id1].size();++i)
		{
			int v=num[id1][i];
			minn=min(minn,calc(v,trie[u][0],id-1));
			num[id0].push_back(v);
		}
		num[id1].clear();
		ID[u]=id0;
	}
	return bck+minn+(1ll<<id-1);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;++i)
		insert(a[i]);
	printf("%lld\n",fun(0,31,0));
	return 0;
}
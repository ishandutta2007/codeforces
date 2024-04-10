#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const long long M=998244353;
int n,i,siiz[200005],u,v,head[200005],Next[400005],adj[400005],k;
long long p[200005],ans=1;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,s=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			s++;
		}
	if(i!=1)
		ans=ans*p[s+1]%M;
	else
		ans=ans*p[s]%M;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	p[0]=1;
	for(i=1;i<=n;i++)
		p[i]=p[i-1]*i%M;
	dfs(1,0);
	cout<<ans*n%M;
}
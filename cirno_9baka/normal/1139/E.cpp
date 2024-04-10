#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=1000000007;
typedef long long ll;
int n,i,m,head[100005],Next[200005],adj[200005],a[10005],b[10005],vis[5005],p[10005],c[10005],l[10005],q,v[10005],t[10005],ans,fans[100005],k;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
bool check(int a)
{
	int i;
	if(vis[a]==1)
		return false;
	vis[a]=1;
	for(i=head[a];i!=0;i=Next[i])
		if(t[adj[i]]!=0)
		{
			bool d=check(t[adj[i]]);
			if(d)
			{
				t[adj[i]]=a;
				return true;
			}
		}
		else
		{
			t[adj[i]]=a;
			return true;
		}
	return false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		p[i]++;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&l[i]);
		v[l[i]]=1;
	}
	for(i=1;i<=n;i++)
		if(v[i]==0)
			Push(p[i],c[i]);
	while(check(++ans))
		memset(vis,0,sizeof(vis));
	fans[q]=ans;
	for(i=q;i>1;i--)
	{
		memset(vis,0,sizeof(vis));
		Push(p[l[i]],c[l[i]]);
		while(check(ans))
		{
			memset(vis,0,sizeof(vis));
			ans++;
		}
		fans[i-1]=ans;
	}
	for(i=1;i<=q;i++)
		printf("%d\n",fans[i]-1);
}
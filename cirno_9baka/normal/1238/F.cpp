//
#include<stdio.h>
#include<iostream>
using namespace std;
const int N=500005;
int n,d[N],i,head[N],Next[N*2],adj[N*2],u,v,k,s[N],ans,q;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
int dfs(int i,int fa)
{
	int mx=d[i],mxx=d[i],j;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			d[adj[j]]=d[i]+s[adj[j]];
			int s=dfs(adj[j],i);
			if(mx<s)
			{
				mxx=mx;
				mx=s;
			}
			else
				mxx=max(mxx,s);
		}
	ans=max(ans,mx+mxx-d[i]*2+s[i]);
	return mx;
}
int main()
{
    scanf("%d",&q);
    while(q--)
	{
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            d[i]=s[i]=head[i]=0;
        k=0;
        ans=0;
	    for(i=1;i<n;i++)
	    {
		    scanf("%d %d",&u,&v);
		    Push(u,v);
		    Push(v,u);
		    s[u]++;
		    s[v]++;
	    }
	    for(i=1;i<=n;i++)
		    s[i]--;
	    dfs(1,0);
	    printf("%d\n",ans+2);
    }
}
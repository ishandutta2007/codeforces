#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=300005;
int n,m;
int U[maxn],V[maxn];
int adj[maxn*2],next[maxn*2];
int head[maxn],tot;
int siz[maxn],fa[maxn],st[maxn],top,vis[maxn];
double C[maxn],W[maxn],sum;
void add(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}

void dfs()
{
  st[++top]=1;
  int u,i;
  while(top)
  {
    u=st[top];
    if(!vis[u])
    {
      vis[u]=1;
      for(i=head[u];i;i=next[i])
        if(adj[i]!=fa[u])
        st[++top]=adj[i],fa[adj[i]]=u;
    }
    else
    {
      top--;
      siz[u]=1;
      for(i=head[u];i;i=next[i])
        if(adj[i]!=fa[u])
        siz[u]+=siz[adj[i]];
    }
  }
}

int main()
{
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    scanf("%d%d%lf",U+i,V+i,W+i);
    add(U[i],V[i]);
    add(V[i],U[i]);
  }
  dfs();
  long long s1,s2,nn=n;
  for(int i=1;i<n;i++)
  {
    if(fa[U[i]]==V[i])swap(U[i],V[i]);
    s1=n-siz[V[i]];
    s2=siz[V[i]];
    C[i]=((double)s1*(s1-1)/2*s2+s2*(s2-1)/2*s1)/((double)nn*(n-1)*(n-2)/6);
    sum+=W[i]*C[i];
  }
  int t,q;double ww;
  scanf("%d",&q);
  for(int i=1;i<=q;i++)
  {
    scanf("%d%lf",&t,&ww);
    sum=sum-C[t]*W[t]+C[t]*ww;
    W[t]=ww;
    printf("%.10lf\n",sum*2);
  }
  return 0;
}
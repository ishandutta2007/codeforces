#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,vis[1<<22],a[1<<22],x,s;
void dfs(int x)
{
if (vis[x]) return;
vis[x]=1;
if (a[x]) dfs(((1<<n)-1)^x);
int i;
for (i=0;i<n;i++) if ((x>>i)&1)
{
dfs(x^(1<<i));
}
}
int main()
{
scanf("%d%d",&n,&m);
for (i=1;i<=m;i++)
{
scanf("%d",&x);
a[x]=1;
}
for (i=0;i<(1<<n);i++) if (a[i]&&!vis[i])
{
dfs(i);
s++;
}
cout<<s;
return 0;
}
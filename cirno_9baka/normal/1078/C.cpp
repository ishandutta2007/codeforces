#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,head[300005],Next[600005],adj[600005],i,u,v,k;
long long f[300005][3];
void Push(int u,int v)
{
    Next[++k]=head[u];
    head[u]=k;
    adj[k]=v;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll g=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return g;
}
ll ni(ll x)
{
    x=(x%M+M)%M;
    ll a,b;
    exgcd(x,M,a,b);
    return a;
}
void dfs(int i,int fa)
{
    int j;
    long long s=1,s2=1;
    for(j=head[i];j!=0;j=Next[j])
        if(adj[j]!=fa)
        {
            dfs(adj[j],i);
            s=s*(f[adj[j]][0]+f[adj[j]][1])%M;
            s2=s2*(f[adj[j]][0]+f[adj[j]][1]*2)%M;
        }
    f[i][0]=s;
    f[i][2]=s2-s;
    for(j=head[i];j!=0;j=Next[j])
        if(adj[j]!=fa)
            f[i][1]=(f[i][1]+s2*ni(f[adj[j]][0]+2*f[adj[j]][1])%M*(f[adj[j]][0]+f[adj[j]][2]))%M;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        Push(u,v);
        Push(v,u);
    }
    dfs(1,0);
    cout<<((f[1][0]+f[1][1])%M+M)%M;
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<cctype>
#define fi first
#define se secode
#define INF 100000000
#define MN 100000
typedef long long LL;
using namespace std;
vector<int> G[405];
char st[1000];
int vis[10005],n,m;
inline int bh(int i,int j)
{
    return (i-1)*m+j;
}
int dfn[MN]={0},low[MN],fr[MN],cnt=0,num=0;
bool stk[MN];
stack<int> s;
void tarjan(int x)
{
    int i,v,len=G[x].size();
    dfn[x]=low[x]=++num;
    s.push(x); stk[x]=1;
    for(i=0;i<len;i++)
    {
        v=G[x][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(stk[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        do
        {
            v=s.top();
            s.pop(); stk[v]=0;
            fr[v]=cnt;
        }while(v!=x);
    }
}

int main()
{
    int i,j;
    cin>>n>>m;
    scanf("%s",st+1);
    for(i=1;i<=n;i++)
    {
        if(st[i]=='<')
        {
            for(j=2;j<=m;j++)
            {
                G[bh(i,j)].push_back(bh(i,j-1));
            }
        }
        else
            for(j=1;j<m;j++)
            {
                G[bh(i,j)].push_back(bh(i,j+1));
            }
    }
    scanf("%s",st+1);
    for(i=1;i<=m;i++)
    {
        if(st[i]=='v')
            for(j=1;j<n;j++)
                G[bh(j,i)].push_back(bh(j+1,i));
        else
            for(j=2;j<=n;j++)
                G[bh(j,i)].push_back(bh(j-1,i));
    }
    tarjan(1);
    int rt=fr[1];
    for(i=1;i<=n*m;i++)
        if(fr[i]!=rt)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}
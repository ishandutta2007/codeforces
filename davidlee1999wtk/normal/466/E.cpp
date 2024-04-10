#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int fa[N],in[N],out[N];
int findr(int x)
{
    return x==fa[x]?x:fa[x]=findr(fa[x]);
}
int op[N],qa[N],qb[N],bo[N],ad[N],mi[N];
int n,m,tot;
vector<int> G[N];
void dfs(int x)
{
    in[x]=++tot;
    int i,v;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
        dfs(v);
    }
    out[x]=tot;
}

int main()
{
    int i,a,b,f1,f2,z=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        fa[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&op[i]);
        if(op[i]==1)
        {
            scanf("%d%d",&a,&b);
            qa[i]=a,qb[i]=b;
            bo[a]=b;
            G[b].push_back(a);
            //G[b].push_back(a);
        }
        else if(op[i]==2)
            scanf("%d",&qa[i]);
        else scanf("%d%d",&qa[i],&qb[i]);
        //debug(op[i]);
    }
    for(i=1;i<=n;i++)
        if(bo[i]==0)
            dfs(i);
    for(i=1;i<=m;i++)
    {
        if(op[i]==1)
        {
            a=qa[i],b=qb[i];
            f1=findr(a);
            f2=findr(b);
            fa[f1]=f2;
        }
        else if(op[i]==2)
        {
            //scanf("%d",&qa[i]);
            z++;
            ad[z]=in[qa[i]];
            f1=findr(qa[i]);
            mi[z]=in[bo[f1]];
        }
        else
        {
            a=qa[i],b=qb[i];
            if(ad[b]>=in[a]&&ad[b]<=out[a])
                if(mi[b]>=in[a]&&mi[b]<=out[a])
                    printf("NO\n");
                else printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
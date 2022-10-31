#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)

using namespace std;

struct vec
{
    long long to, next;
}E[210000*2];
long long shit[210000], cnt, n, rt, rtf, sum, cnttt[210000],sz[210000];
bool visit[210000];
long long tim[2010000],v[2010000], T;
char s[210000];
long long ans[210000], tE[210000], tot;
void addedge(int x,int y)
{
    E[++cnt].to = y;
    E[cnt].next = shit[x];
    shit[x] = cnt;
}
void modify(int x,int y)
{
    addedge(x, y);
    addedge(y, x);
}
void getttrtt(int x, int fa)
{
    int i;
    long long y;
    sz[x] = 1;
    cnttt[x] = 0;
    for(i = shit[x]; i; i = E[i].next)
    {
        y = E[i].to;
        if(!visit[y] && y != fa)
        {
            getttrtt(y, x);
            sz[x] += sz[y];
            cnttt[x] = max(cnttt[x], sz[y]);
        }
    }
    if (sum-sz[x]>cnttt[x])cnttt[x] =  sum - sz[x];
    if(cnttt[x] < cnttt[rt]) { rt = x; rtf = fa; }
}

void add(int x, long long y)
{
    if(tim[x] != T) v[x] = 0;
    tim[x] = T;
    v[x] += y;
}
long long ask(int x)
{
    if(tim[x] != T) v[x] = 0;
    return v[x];
}
long long dfs1(int x, int fa, long long now)
{
    long long i,y;
    long long res = 0;
    now ^= (1 << s[x]);
    res += ask(now);
    rep(i, 0, 19)
        (res += ask(now ^ (1 << i)));
    for(i = shit[x]; i; i = E[i].next)
    {
        y=E[i].to;
        if(!visit[y] && y != fa)
            res += dfs1(y, x, now);
    }
    ans[x] += res;
    return res;
}
void dfs2(int x, int fa, long long now)
{
    long long i,y;
    now ^= (1 << s[x]);
    add(now, 1);
    for(i = shit[x]; i; i = E[i].next)
    {
        y = E[i].to;
        if(!visit[y] && y != fa)
            dfs2(y, x, now);
    }
}
void work(long long x)
{
    long long i,y;
    visit[x] = 1;
    T ++;
    add(0, 1);
    tot = 0;
    for(i = shit[x]; i; i = E[i].next)
    {
        y = E[i].to;
        if(!visit[y])
        {
            tE[++ tot] = y;
            (ans[x] += dfs1(y, x, 1 << s[x]));
            dfs2(y, x, 0);
        }
    }
    T ++;
    for(i = tot; i; i --)
    {
        y = tE[i];
        dfs1(y, x, 1 <<s[x]);
        dfs2(y, x, 0);
    }
    for(i = shit[x]; i; i = E[i].next)
    {
        y = E[i].to;
        if(!visit[y])
        {
            rt = 0;
            sum = sz[y];
            getttrtt(y, x);
            sz[rtf] = sum - sz[rt];
            work(rt);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        modify(x,y);
    }
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)s[i] -= 'a';
    cnttt[0]=1000000007;
    sum = n;
    getttrtt(1, 0);
    work(rt);
    for(int i=1;i<=n;i++)printf("%lld ", ans[i] + 1);
    return 0;
}
//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,l[1000005],r[1000005],u[1000005],d[1000005],a,b,c,g[1000005],cnt,ans;
struct L{
    int p,v;
}h[1000005];
int lowbit(int now)
{
    return now&-now;
}
void add(int now,int v)
{
    while(now<=1000000)
    {
        g[now]+=v;
        now+=lowbit(now);
    }
}
int ask(int now)
{
    int tmp=0;
    while(now>0)
    {
        tmp+=g[now];
        now-=lowbit(now);
    }
    return tmp;
}
bool cmpl(const L &A,const L &B)
{
    return A.v<B.v;
}
bool cmpr(const L &A,const L &B)
{
    return A.v>B.v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<1000000;++i)
    {
        l[i]=0;
        r[i]=1000000;
        u[i]=1000000;
        d[i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b>>c;
        if(b==0)
        {
            l[a]=max(l[a],c);
        }
        if(c==1000000)
        {
            r[a]=min(r[a],b);
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        if(b==0)
        {
            d[a]=max(d[a],c);
        }
        if(c==1000000)
        {
            u[a]=min(u[a],b);
        }
    }
    for(int i=1;i<1000000;++i)
    {
        if(l[i]>=r[i])
        {
            l[i]=1000000;
            r[i]=1000000;
            ++ans;
        }
        if(d[i]>=u[i])
        {
            d[i]=1000000;
            u[i]=1000000;
            ++ans;
        }
    }
    for(int i=1;i<1000000;++i)
    {
        h[i].p=i;
        h[i].v=l[i];
        add(i,1);
    }
    sort(h+1,h+1000000,cmpl);
    cnt=0;
    for(int i=1;i<1000000;++i)
    {
        while(++cnt<1000000&&h[cnt].v<i)
        {
            add(h[cnt].p,-1);
        }
        --cnt;
        ans+=ask(d[i]);
        ans+=ask(1000000)-ask(u[i]-1);
    }
    memset(g,0,sizeof(g));
    for(int i=1;i<1000000;++i)
    {
        h[i].p=i;
        h[i].v=r[i];
        add(i,1);
    }
    sort(h+1,h+1000000,cmpr);
    cnt=0;
    for(int i=999999;i;--i)
    {
        while(++cnt<1000000&&h[cnt].v>i)
        {
            add(h[cnt].p,-1);
        }
        --cnt;
        ans+=ask(d[i]);
        ans+=ask(1000000)-ask(u[i]-1);
    }
    cout<<ans+1<<endl;
    return 0;
}
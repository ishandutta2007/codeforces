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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<pii,int> vis;
map<LL,int> dp;
map<LL,pii> mp;
set<LL> s;
LL ans=(LL)2000000000*1000000000,s1,s2;
pii a1,a2;
bool flag=0;
inline void fix(pii &x)
{
    if(x.fi>x.se) swap(x.fi,x.se);
}
inline LL mj(pii x)
{
    return (LL)x.fi*x.se;
}
void bfs1(pii st)
{
    fix(st);
    vis.clear();
    queue<pii> q;
    pii x,y;
    int bs=-1,sz;
    LL ts;
    q.push(st);
    vis[st]=1;
    dp[mj(st)]=0;
    mp[mj(st)]=st;
    s.insert(mj(st));
    while(!q.empty())
    {
        sz=q.size();
        bs++;
        while(sz--)
        {
            x=q.front(),q.pop();
            if(x.fi%2==0)
            {
                y=make_pair(x.fi/2,x.se);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(!s.count(ts)||dp[ts]>bs+1)
                    {
                        if(!s.count(ts))
                            s.insert(ts);
                        dp[mj(y)]=bs+1;
                        mp[ts]=y;
                    }
                }
            }
            if(x.fi%3==0)
            {
                y=make_pair(x.fi/3*2,x.se);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(!s.count(ts)||dp[ts]>bs+1)
                    {
                        if(!s.count(ts))
                            s.insert(ts);
                        dp[mj(y)]=bs+1;
                        mp[ts]=y;
                    }
                }
            }
            if(x.se%2==0)
            {
                y=make_pair(x.fi,x.se/2);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(!s.count(ts)||dp[ts]>bs+1)
                    {
                        if(!s.count(ts))
                            s.insert(ts);
                        dp[mj(y)]=bs+1;
                        mp[ts]=y;
                    }
                }
            }
            if(x.se%3==0)
            {
                y=make_pair(x.fi,x.se/3*2);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(!s.count(ts)||dp[ts]>bs+1)
                    {
                        if(!s.count(ts))
                            s.insert(ts);
                        dp[mj(y)]=bs+1;
                        mp[ts]=y;
                    }
                }
            }
        }
    }
}

void bfs2(pii st)
{
    fix(st);
    vis.clear();
    queue<pii> q;
    pii x,y;
    LL ts;
    int sz,bs=0;
    q.push(st);
    vis[st]=1;
    y=st,ts=mj(y);
    if(s.count(ts))
    {
        if(ans>bs+dp[ts])
        {
            ans=bs+dp[ts];
            a1=mp[ts];
            a2=y;
        }
    }
    while(!q.empty())
    {
        sz=q.size();
        bs++;
        while(sz--)
        {
            x=q.front(),q.pop();
            if(x.fi%2==0)
            {
                y=make_pair(x.fi/2,x.se);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    ts=mj(y);
                    if(s.count(ts))
                    {
                        if(ans>bs+dp[ts])
                        {
                            ans=bs+dp[ts];
                            a1=mp[ts];
                            a2=y;
                        }
                    }
                    q.push(y);
                }
            }
            if(x.fi%3==0)
            {
                y=make_pair(x.fi/3*2,x.se);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(s.count(ts))
                    {
                        if(ans>bs+dp[ts])
                        {
                            ans=bs+dp[ts];
                            a1=mp[ts];
                            a2=y;
                        }
                    }
                    q.push(y);
                }
            }
            if(x.se%2==0)
            {
                y=make_pair(x.fi,x.se/2);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(s.count(ts))
                    {
                        if(ans>bs+dp[ts])
                        {
                            ans=bs+dp[ts];
                            a1=mp[ts];
                            a2=y;
                        }
                    }
                    q.push(y);
                }
            }
            if(x.se%3==0)
            {
                y=make_pair(x.fi,x.se/3*2);
                fix(y);
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                    ts=mj(y);
                    if(s.count(ts))
                    {
                        if(ans>bs+dp[ts])
                        {
                            ans=bs+dp[ts];
                            a1=mp[ts];
                            a2=y;
                        }
                    }
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    int r1,c1,r2,c2;
    a1.fi=-1;
    cin>>r1>>c1>>r2>>c2;
    bfs1(make_pair(r1,c1));
    bfs2(make_pair(r2,c2));
    if(a1.fi==-1) printf("-1\n");
    else
    {
        cout<<ans<<endl;
        printf("%d %d\n",(int)(a1.fi),(int)a1.se);
        printf("%d %d\n",(a2.fi),a2.se);
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N=5000+5;

int n,m,d[N][N];
vector<int>g[N];

struct store
{
    int nod;
    int cnt;
    int pri;
};

vector<store>v;


bool cmp(store a,store b)
{
    return a.pri<b.pri;
}

inline void build_d()
{
    for(register int i=1;i<=n;i++)
    {
        for(register int j=1;j<=n;j++)
        {
            d[i][j]=-1;
        }
        d[i][i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            register int nod=q.front();
            q.pop();
            for(auto &nou:g[nod])
            {
                if(d[i][nou]==-1)
                {
                    d[i][nou]=1+d[i][nod];
                    q.push(nou);
                }
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(register int i=1;i<=m;i++)
    {
        register int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>m;
    for(register int i=1;i<=m;i++)
    {
        register int nod,a,b;
        cin>>nod>>a>>b;
        v.push_back({nod,a,b});
    }
    build_d();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]==-1)
            {
                d[i][j]=(1<<30);
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    register int q;
    cin>>q;
    while(q--)
    {
        register int nod;
        register int cnt;
        register int buget;
        cin>>nod>>cnt>>buget;
        register int lo=0;
        register int hi=n;
        register int ans=-1;
        while(lo<=hi)
        {
            register int mid=(lo+hi)>>1;
            int s=0;
            for(auto &it:v)
            {
                if(d[nod][it.nod]<=mid)
                {
                    s+=it.cnt;
                    if(s>=cnt)
                    {
                        break;
                    }
                }
            }
            if(s<cnt)
            {
                lo=mid+1;
                continue;
            }
            register int need=cnt;
            long long co=0;
            for(auto &it:v)
            {
                if(d[nod][it.nod]<=mid)
                {
                    register int t=min(need,it.cnt);
                    need-=t;
                    co+=t*(long long)it.pri;
                    if(need==0)
                    {
                        break;
                    }
                }
            }
            if(need==0 && co<=buget)
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
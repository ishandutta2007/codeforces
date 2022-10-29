#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
vector<int>v[1009];
bool mark[1009];
int ds[1009];
int dt[1009];
signed main()
{
    ios_base::sync_with_stdio(false);
    #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m ,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=0;i<1009;i++)
    {
        mark[i]=0;
        ds[i]=1000000000;
    }
    ds[s]=0;
    set<pair<int,int>>s1;
    s1.insert(mp(0,s));
    mark[s]=1;
    while(!s1.empty())
    {
        auto x=*(s1.begin());
        s1.erase(s1.begin());
        mark[x.second]=1;
        // cout<<x.second;
        for(auto z:v[(x.second)])
        {
            if(mark[z]==0&&ds[z]>ds[x.second]+1)
            {
                if(ds[z]!=1000000000)
                s1.erase(mp(ds[z],z));
                ds[z]=ds[x.second]+1;
                s1.insert(mp(ds[z],z));
            }
        }
    }
    for(int i=0;i<1009;i++)
    {
        mark[i]=0;
        dt[i]=1000000000;
    }
    dt[t]=0;
    s1.clear();
    s1.insert(mp(0,t));
    mark[t]=1;
    while(!s1.empty())
    {
        auto x=*s1.begin();
        s1.erase(s1.begin());
        mark[x.second]=1;
        for(auto z:v[(x.second)])
        {
            if(mark[z]==0&&dt[z]>dt[x.second]+1)
            {
                if(dt[z]!=1000000000)
                s1.erase(mp(dt[z],z));
                dt[z]=dt[x.second]+1;
                s1.insert(mp(dt[z],z));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if(ds[i]+dt[j]+1>=ds[t]&&dt[i]+ds[j]+1>=ds[t])
                {
                    ans++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto x:v[i])
        {
            if(ds[i]+dt[x]+1>=ds[t])
            {
                ans--;
            }
        }
    }
    cout<<ans/2;
    return 0;
}
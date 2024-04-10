#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=500000+5;

int n,k;
int v[N];

inline void make_min(int x)
{
    int lft=k;
    for(int i=1;i<=n;i++)
    {
        if(v[i]<x)
        {
            lft-=(x-v[i]);
            v[i]=x;
        }
    }
    for(int i=1;i<=n && lft;i++)
    {
        if(v[i]==x)
        {
            v[i]++;
            lft--;
        }
    }
}

inline void make_max(int x)
{
    int lft=k;
    for(int i=1;i<=n;i++)
    {
        if(x<v[i])
        {
            lft-=(v[i]-x);
            v[i]=x;
        }
    }
    for(int i=1;i<=n && lft;i++)
    {
        if(v[i]==x)
        {
            v[i]--;
            lft--;
        }
    }
}

inline void slove()
{
    int mi,ma;
    mi=v[1];
    ma=v[1];
    for(int i=2;i<=n;i++)
    {
        mi=min(mi,v[i]);
        ma=max(ma,v[i]);
    }
    cout<<ma-mi<<"\n";
}

int32_t main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int lo,hi,ans;
    /// Fix Min +
    int r=0,pas=(1<<30);
    while(pas)
    {
        int mid=r+pas;
        int co=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i]<mid)
            {
                co+=mid-v[i];
            }
        }
        if(co<=k)
        {
            r+=pas;
        }
        pas/=2;
    }
    make_min(r);
    /// Fix Max -
    r=0,pas=(1<<30);
    while(pas)
    {
        int mid=r+pas;
        int co=0;
        for(int i=1;i<=n;i++)
        {
            if(mid<v[i])
            {
                co+=v[i]-mid;
            }
        }
        if(co>k)
        {
            r+=pas;
        }
        pas/=2;
    }
    r++;
    make_max(r);
    slove();

    return 0;
}
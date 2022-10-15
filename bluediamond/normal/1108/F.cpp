#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int t[N];

int dad(int a)
{
    if(a==t[a])
    {
        return a;
    }
    else
    {
        t[a]=dad(t[a]);
        return t[a];
    }
}

void uni(int a,int b)
{
    a=dad(a);
    b=dad(b);
    if(a!=b)
    {
        t[a]=b;
    }
}

map<int,vector<pair<int,int>>>mp;

int n,m;

bool kol[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        t[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,x;
        cin>>a>>b>>x;
        mp[x].push_back({a,b});
    }
    int res=0;
    for(auto &it:mp)
    {
        vector<pair<int,int>>a=it.second;
        int itt=0;
        int cnt=0;
        for(auto &krr:a)
        {
            itt++;
            int x=krr.first;
            int y=krr.second;
            x=dad(x);
            y=dad(y);
            if(x!=y)
            {
                kol[itt]=1;
            }
            else
            {
                kol[itt]=0;
            }
        }
        ///cout<<"cin"<<it.first<<"\n";
        itt=0;
        for(auto &krr:a)
        {
            itt++;
            int x=krr.first;
            int y=krr.second;
            x=dad(x);
            y=dad(y);
            if(x==y && kol[itt]) res++;
            uni(x,y);
        }

    }
    cout<<res<<"\n";
    return 0;
}
/**

**/
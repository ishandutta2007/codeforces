#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500+5;

int n,m;
int x[N];

vector<pair<int,int>>g[N];

bool viz[N];

ld calc(vector<int>vert)
{
    for(int i=1;i<=n;i++)
    {
        viz[i]=0;
    }
    ld a=0;
    ld b=0;
    for(auto &nod:vert)
    {
        viz[nod]=1;
        a+=x[nod];
    }
    for(auto &nod:vert)
    {
        for(auto &it:g[nod])
        {
            int nou=it.first;
            int co=it.second;
            if(viz[nou])
            {
                b+=co;
            }
        }
    }
    b/=2;
    if(b==0)
    {
        return 0;
    }
    return a/b;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        g[a].push_back({b,d});
        g[b].push_back({a,d});
    }
    ld res=0;
    for(int i=1;i<=n;i++)
    {
        for(auto &it:g[i])
        {
            int j=it.first;
            if(j>i)
            {
                res=max(res,calc({i,j}));
            }
        }
    }
    cout<<fixed<<setprecision(9)<<res<<"\n";
    return 0;
}
/**

**/
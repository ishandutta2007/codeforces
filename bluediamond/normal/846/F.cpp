#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000000+5;
const int LIM=1000000+5;

int n;
int v[N];

ll sum=0LL;
ll cnt=0LL;

inline void print()
{
    ld ans=(ld)sum/(ld)cnt;
    cout<<fixed<<setprecision(4)<<ans<<"\n";
    exit(0);
}

vector<int>where[LIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int x=1;x<LIM;x++)
    {
        where[x].push_back(0);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        where[v[i]].push_back(i);
    }
    for(int x=1;x<LIM;x++)
    {
        where[x].push_back(n+1);
    }
    sum+=n;
    cnt+=n;
    for(ll len=2;len<=n;len++)
    {
        ll cate=2*(n+1-len);
        cnt+=cate;
        sum+=cate*len;
    }
    ll scad=0LL;
    for(int x=1;x<LIM;x++)
    {
        if(where[x].size()==2) continue;
        vector<pair<int,int>>interval;
        for(int i=0;i+1<where[x].size();i++)
        {
            interval.push_back({where[x][i],where[x][i+1]-1});
        }
        ll s=0LL;
        ll pp=0LL;
        for(int i=0;i<interval.size();i++)
        {
            int st=interval[i].first;
            int dr=interval[i].second;
            if(st<=dr)
            {
                int cnt=(dr-st+1);
                if(i!=0)
                {
                    s+=cnt*(long long)(st*(long long)(i-1LL)-pp);
                }
                pp+=cnt*i;
            }
        }
        scad+=s*(long long)2;
    }
    sum-=scad;
    print();
    return 0;
}
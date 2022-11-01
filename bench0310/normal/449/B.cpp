#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<pair<int,long long>> v[n+1];
    vector<array<int,3>> one;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        one.push_back({a,b,c});
        one.push_back({b,a,c});
    }
    vector<int> cnt(n+1,0);
    for(int i=0;i<k;i++)
    {
        int b,c;
        scanf("%d%d",&b,&c);
        v[1].push_back({b,c});
        cnt[b]++;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    vector<long long> d(n+1,(1ll<<60));
    d[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        auto [dist,a]=q.top();
        q.pop();
        if(d[a]<dist) continue;
        for(auto [to,w]:v[a])
        {
            if(dist+w<d[to])
            {
                d[to]=dist+w;
                q.push({d[to],to});
            }
        }
    }
    vector<bool> t(n+1,0);
    for(auto [a,b,c]:one) if(d[a]+c==d[b]) t[b]=1;
    int res=0;
    for(int i=2;i<=n;i++) res+=cnt[i]-(1-t[i]);
    printf("%d\n",res);
    return 0;
}
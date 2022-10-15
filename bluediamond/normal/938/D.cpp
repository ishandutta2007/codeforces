#include <bits/stdc++.h>

using namespace std;

const int N=200000+5;

int n,m;
vector< pair<int,long long> >g[N];
long long ans[N];
priority_queue< pair<long long,int> >q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        long long d;
        cin>>a>>b>>d;
        d+=d;
        g[a].push_back({b,d});
        g[b].push_back({a,d});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>ans[i];
        q.push({-ans[i],i});
    }
    while(!q.empty())
    {
        long long cost=-q.top().first;
        int nod=q.top().second;
        q.pop();
        if(cost!=ans[nod])
            continue;
        for(auto &it:g[nod])
        {
            int nou=it.first;
            if(cost+it.second<ans[nou])
            {
                ans[nou]=cost+it.second;
                q.push({-ans[nou],nou});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
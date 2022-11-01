#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> opt[n];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        opt[a].push_back({b,c});
    }
    const int inf=(1<<30);
    queue<int> q[n];
    for(int i=0;i<n;i++)
    {
        vector<int> d(n,inf);
        int cost=inf;
        for(int j=0;j<(int)opt[i].size();j++) cost=min(cost,opt[i][j][1]); //all d are [cost,cost+n-1]
        auto ok=[&](int dist)->bool{return (cost<=dist&&dist<=cost+n-1);};
        for(auto [b,c]:opt[i])
        {
            if(ok(c)&&c<d[b])
            {
                d[b]=c;
                q[c-cost].push(b);
            }
        }
        for(int o=0;o<n;o++)
        {
            while(!q[o].empty())
            {
                int a=q[o].front();
                q[o].pop();
                int dnow=o+cost;
                if(d[a]<dnow) continue;
                //use earlier cannon
                if(ok(dnow+1)&&dnow+1<d[(a+1)%n])
                {
                    d[(a+1)%n]=dnow+1;
                    q[dnow+1-cost].push((a+1)%n);
                }
                //use cannons
                for(auto [b,c]:opt[a])
                {
                    int to=(b+d[a])%n;
                    if(ok(dnow+c)&&dnow+c<d[to])
                    {
                        d[to]=dnow+c;
                        q[dnow+c-cost].push(to);
                    }
                }
            }
        }
        d[i]=0;
        for(int j=0;j<n;j++) cout << d[j] << " \n"[j==n-1];
    }
    return 0;
}
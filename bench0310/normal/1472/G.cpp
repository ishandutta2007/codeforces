#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> v[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        queue<int> q;
        vector<int> d(n+1,-1);
        d[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int to:v[a])
            {
                if(d[to]==-1)
                {
                    d[to]=d[a]+1;
                    q.push(to);
                }
            }
        }
        vector<array<int,2>> ord;
        for(int i=1;i<=n;i++) ord.push_back({d[i],i});
        sort(ord.begin(),ord.end(),greater<>());
        vector<int> best(n+1,0);
        for(int i=1;i<=n;i++) best[i]=d[i];
        for(auto [da,a]:ord)
        {
            for(int to:v[a])
            {
                if(d[to]>da) best[a]=min(best[a],best[to]);
                else best[a]=min(best[a],d[to]);
            }
        }
        for(int i=1;i<=n;i++) cout << best[i] << " \n"[i==n];
    }
    return 0;
}
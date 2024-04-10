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
        int n,k;
        cin >> n >> k;
        vector<int> v[n+1];
        vector<int> d(n+1,0);
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            d[a]++; d[b]++;
        }
        int r=0;
        queue<array<int,2>> q;
        for(int i=1;i<=n;i++) if(d[i]<=1) q.push({i,1});
        while(!q.empty())
        {
            auto [a,m]=q.front();
            q.pop();
            if(m>k) break;
            r++;
            for(int to:v[a]) if((--d[to])==1) q.push({to,m+1});
        }
        cout << n-r << "\n";
    }
    return 0;
}
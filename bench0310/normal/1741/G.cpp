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
            v[b].push_back(a);
        }
        int f;
        cin >> f;
        vector<int> h(f+1,0);
        for(int i=1;i<=f;i++) cin >> h[i];
        vector<int> car(f+1,1);
        int k;
        cin >> k;
        vector<int> hmask(n+1,0);
        for(int i=0;i<k;i++)
        {
            int p;
            cin >> p;
            car[p]=0;
            hmask[h[p]]|=(1<<i);
        }
        vector<int> d(n+1,-1);
        queue<int> q;
        auto add=[&](int a,int nd)
        {
            if(d[a]==-1)
            {
                d[a]=nd;
                q.push(a);
            }
        };
        add(1,0);
        vector dp(n+1,vector(1<<k,int(0)));
        dp[1][0]=1;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int to:v[a])
            {
                add(to,d[a]+1);
                if(d[to]==d[a]+1)
                {
                    for(int j=0;j<(1<<k);j++) if(dp[a][j]==1) dp[to][j|hmask[to]]=1;
                }
            }
        }
        vector<int> opt(1<<k,0);
        opt[0]=1;
        for(int i=1;i<=f;i++)
        {
            if(car[i]==0) continue;
            for(int j=(1<<k)-1;j>=0;j--) if(opt[j]==1) for(int nj=0;nj<(1<<k);nj++) if(dp[h[i]][nj]==1) opt[j|nj]=1;
        }
        int res=k;
        for(int j=0;j<(1<<k);j++) if(opt[j]==1) res=min(res,k-popcount(uint32_t(j)));
        cout << res << "\n";
    }
    return 0;
}
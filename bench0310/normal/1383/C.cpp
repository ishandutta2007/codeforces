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
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector<int> v[20];
        vector<int> in(20,0);
        for(int i=0;i<n;i++)
        {
            int x=(a[i]-'a'),y=(b[i]-'a');
            if(x!=y)
            {
                v[x].push_back(y);
                v[y].push_back(x);
                in[y]|=(1<<x);
            }
        }
        int c=20;
        vector<bool> vis(20,0);
        function<void(int)> dfs=[&](int x)
        {
            vis[x]=1;
            for(int to:v[x]) if(!vis[to]) dfs(to);
        };
        for(int i=0;i<20;i++)
        {
            if(vis[i]) continue;
            dfs(i);
            c--;
        }
        auto chmin=[&](int &x,int y){x=min(x,y);};
        vector<int> dp((1<<20),50);
        dp[0]=0;
        for(int m=0;m<(1<<20);m++)
        {
            for(int i=0;i<20;i++)
            {
                if(m&(1<<i)) continue;
                chmin(dp[m^(1<<i)],dp[m]+1-((m&in[i])==in[i]));
            }
        }
        cout << c+dp[(1<<20)-1] << "\n";
    }
    return 0;
}
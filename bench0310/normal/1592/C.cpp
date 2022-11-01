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
        vector<int> a(n+1,0);
        int all=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            all^=a[i];
        }
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> x(n+1,0);
        vector<int> cnt(n+1,0);
        bool res=(all==0);
        function<void(int,int)> dfs=[&](int e,int p)
        {
            x[e]=a[e];
            for(int to:v[e])
            {
                if(to==p) continue;
                dfs(to,e);
                x[e]^=x[to];
                cnt[e]+=cnt[to];
            }
            if(x[e]==all) cnt[e]++;
            res|=(x[e]==0&&cnt[e]>0);
        };
        function<void(int,int,int)> go=[&](int e,int p,int u)
        {
            res|=(x[e]==all&&cnt[e]+u<cnt[1]);
            for(int to:v[e])
            {
                if(to==p) continue;
                go(to,e,u+(x[e]==all));
            }
        };
        if(all!=0)
        {
            if(k==2) res=0;
            else
            {
                dfs(1,0);
                go(1,0,0);
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
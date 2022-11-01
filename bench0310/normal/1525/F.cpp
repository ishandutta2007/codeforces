#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    vector<ll> x(k+1,0);
    vector<ll> y(k+1,0);
    for(int i=1;i<=k;i++) cin >> x[i] >> y[i];
    vector<bool> badl(n+1,0);
    vector<bool> badr(n+1,0);
    auto max_mathing=[&]()->int
    {
        vector<int> mt(n+1,0);
        vector<bool> vis(n+1,0);
        function<bool(int)> go=[&](int a)->bool
        {
            if(badl[a]||vis[a]) return 0;
            vis[a]=1;
            for(int to:v[a])
            {
                if(badr[to]==0&&(mt[to]==0||go(mt[to])))
                {
                    mt[to]=a;
                    return 1;
                }
            }
            return 0;;
        };
        for(int i=1;i<=n;i++)
        {
            vis.assign(n+1,0);
            go(i);
        }
        int sz=0;
        for(int i=1;i<=n;i++) sz+=(mt[i]!=0);
        return sz;
    };
    auto opt=[&](int a,int t,int best)->bool
    {
        vector<bool> &bad=(t==0?badl:badr);
        if(bad[a]==1) return 0;
        bad[a]=1;
        if(max_mathing()<best) return 1;
        bad[a]=0;
        return 0;
    };
    vector<int> ord;
    vector<int> req(k+1,0);
    for(int i=1;i<=k;i++)
    {
        int now=max_mathing();
        while(n-now<=i)
        {
            for(int j=1;j<=n;j++)
            {
                for(int t=0;t<2;t++)
                {
                    if(opt(j,t,now))
                    {
                        ord.push_back((t==0?1:-1)*j);
                        req[i]++;
                        now--;
                        goto done;
                    }
                }
            }
            done:;
        }
    }
    int all=ord.size();
    vector<vector<array<ll,2>>> dp(k+2,vector<array<ll,2>>(all+1,{0,0}));
    int sum=0;
    for(int i=k;i>=1;i--)
    {
        int nsum=sum+req[i];
        for(int j=0;j<=sum;j++)
        {
            for(int t=0;j+t<=nsum;t++)
            {
                dp[i][j+t]=max(dp[i][j+t],{dp[i+1][j][0]+max(0ll,x[i]-t*y[i]),j});
            }
        }
        sum=nsum;
    }
    vector<int> res;
    int cnt=sum;
    int idx=0;
    for(int i=1;i<=k;i++)
    {
        int nxt=dp[i][cnt][1];
        int now=cnt-nxt;
        while(now--) res.push_back(ord[idx++]);
        res.push_back(0);
        cnt=nxt;
    }
    cout << res.size() << "\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}
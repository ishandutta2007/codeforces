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
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        const int mod=1000000007;
        auto add=[&](int a,int b)->int{return (a+b-(a+b>=mod?mod:0));};
        auto mul=[&](int a,int b)->int{return (ll(a)*b)%mod;};
        vector c(n+1,vector(n+1,int(0)));
        for(int i=0;i<=n;i++) c[i][0]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=add(c[i-1][j],c[i-1][j-1]);
        int res=0;
        if(k==1) res=n;
        else if(k==2) res=c[n][2];
        else
        {
            for(int i=1;i<=n;i++)
            {
                vector<int> d(n+1,-1);
                d[i]=0;
                queue<array<int,2>> q;
                q.push({i,0});
                vector cnt(n+1,vector(n+1,int(0)));
                while(!q.empty())
                {
                    auto [a,p]=q.front();
                    q.pop();
                    cnt[p][d[a]]++;
                    for(int to:v[a])
                    {
                        if(d[to]==-1)
                        {
                            d[to]=d[a]+1;
                            q.push({to,(p==0?to:p)});
                        }
                    }
                }
                for(int j=1;j<=n;j++)
                {
                    vector<int> dp(k+1,0);
                    dp[0]=1;
                    for(int to:v[i])
                    {
                        for(int x=k-1;x>=0;x--)
                        {
                            dp[x+1]=add(dp[x+1],mul(cnt[to][j],dp[x]));
                        }
                    }
                    res=add(res,dp[k]);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
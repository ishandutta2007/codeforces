#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin >> n >> d;
    vector<array<ld,10>> dp(n+1);
    vector<vector<array<int,2>>> p(n+1,vector<array<int,2>>(10,{-1,-1}));
    for(int i=0;i<=n;i++) dp[i].fill(0);
    p[0][1]={0,0};
    vector<int> t(n+1,0);
    vector<pair<ld,int>> best(10,{0,-1});
    for(int i=1;i<=n;i++)
    {
        cin >> t[i];
        ld a=log(ld(t[i]));
        dp[i][t[i]%10]=a;
        p[i][t[i]%10]={0,1};
        for(int j=0;j<=9;j++)
        {
            if(best[j].second==-1) continue;
            int nj=(j*t[i])%10;
            if(best[j].first+a>dp[i][nj])
            {
                dp[i][nj]=best[j].first+a;
                p[i][nj]={best[j].second,j};
            }
        }
        for(int j=0;j<=9;j++)
        {
            if(p[i][j][0]!=-1) best[j]=max(best[j],{dp[i][j],i});
        }
    }
    if(best[d].second!=-1)
    {
        int x=best[d].second;
        vector<int> res;
        while(x!=0)
        {
            res.push_back(t[x]);
            auto [nx,nd]=p[x][d];
            x=nx;
            d=nd;
        }
        sort(res.begin(),res.end());
        cout << res.size() << "\n";
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}
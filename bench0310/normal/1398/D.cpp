#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> x(a);
    for(int i=0;i<a;i++) cin >> x[i];
    sort(x.begin(),x.end(),greater<int>());
    vector<int> y(b);
    for(int i=0;i<b;i++) cin >> y[i];
    sort(y.begin(),y.end(),greater<int>());
    vector<int> z(c);
    for(int i=0;i<c;i++) cin >> z[i];
    sort(z.begin(),z.end(),greater<int>());
    vector<vector<vector<int>>> dp(a+1,vector<vector<int>>(b+1,vector<int>(c+1,0)));
    auto mx=[](int &d,int e){d=max(d,e);};
    int res=0;
    for(int o=0;o<=a;o++)
    {
        for(int i=0;i<=b;i++)
        {
            for(int j=0;j<=c;j++)
            {
                mx(res,dp[o][i][j]);
                if(o+1<=a&&i+1<=b) mx(dp[o+1][i+1][j],dp[o][i][j]+x[o]*y[i]);
                if(o+1<=a&&j+1<=c) mx(dp[o+1][i][j+1],dp[o][i][j]+x[o]*z[j]);
                if(i+1<=b&&j+1<=c) mx(dp[o][i+1][j+1],dp[o][i][j]+y[i]*z[j]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}
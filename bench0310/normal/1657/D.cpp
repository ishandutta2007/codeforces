#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,C;
    cin >> n >> C;
    vector<ll> opt(C+1,0);
    for(int i=1;i<=n;i++)
    {
        int c,d,h;
        cin >> c >> d >> h;
        opt[c]=max(opt[c],ll(d)*h);
    }
    vector<ll> dp(C+1,0);
    for(int i=1;i<=C;i++)
    {
        for(int j=1;i*j<=C;j++) dp[i*j]=max(dp[i*j],j*opt[i]);
    }
    for(int i=1;i<=C;i++) dp[i]=max(dp[i],dp[i-1]);
    int m;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        ll d,h;
        cin >> d >> h;
        int p=ranges::upper_bound(dp,d*h)-dp.begin();
        cout << (p<=C?p:-1) << " \n"[i==m];
    }
    return 0;
}
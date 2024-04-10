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
        vector<int> a(n);
        for(int &x:a) cin >> x;
        int g=0;
        for(int i=0;i<m;i++)
        {
            int b;
            cin >> b;
            g=gcd(g,b);
        }
        array<ll,2> res={0,0};
        for(int i=0;i<g;i++)
        {
            array<ll,2> dp={0,-(1ll<<60)};
            for(int j=i;j<n;j+=g) dp={max(dp[0]+a[j],dp[1]-a[j]),max(dp[1]+a[j],dp[0]-a[j])};
            for(int j=0;j<2;j++) res[j]+=dp[j];
        }
        cout << max(res[0],res[1]) << "\n";
    }
    return 0;
}
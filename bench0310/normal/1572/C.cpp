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
        vector<int> v[n+1];
        vector<int> a(n+1,0);
        vector<int> p(n+1,0);
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            p[i]=v[a[i]].size();
            c[a[i]]++;
            v[a[i]].push_back(i);
        }
        vector dp(n+1,vector(n+1,0));
        auto chmax=[&](int &x,int y){x=max(x,y);};
        for(int sz=2;sz<=n;sz++)
        {
            for(int l=1;l+sz-1<=n;l++)
            {
                int r=l+sz-1;
                dp[l][r]=dp[l+1][r];
                for(int j=p[l]+1;j<c[a[l]]&&v[a[l]][j]<=r;j++) chmax(dp[l][r],dp[l+1][v[a[l]][j]-1]+dp[v[a[l]][j]][r]+1);
            }
        }
        cout << n-1-dp[1][n] << "\n";
    }
    return 0;
}
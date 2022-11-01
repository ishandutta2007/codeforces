#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> pos={0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]==1) pos.push_back(i);
    }
    int m=(int)pos.size()-1;
    const int inf=(1<<30);
    vector<int> dp(m+1,inf);
    dp[0]=0;
    int res=inf;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) continue;
        for(int j=m-1;j>=0;j--) dp[j+1]=min(dp[j+1],dp[j]+abs(i-pos[j+1]));
        res=min(res,dp[m]);
    }
    cout << res << "\n";
    return 0;
}
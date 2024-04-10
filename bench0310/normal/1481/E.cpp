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
    vector<int> l(n+1,0);
    vector<int> r(n+1,0);
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(l[a[i]]==0) l[a[i]]=i;
        r[a[i]]=i;
    }
    vector<int> dp(n+2,0);
    for(int i=n;i>=1;i--)
    {
        cnt[a[i]]++;
        if(l[a[i]]==i) dp[i]=(cnt[a[i]]+dp[r[a[i]]+1]);
        else dp[i]=cnt[a[i]];
        dp[i]=max(dp[i],dp[i+1]);
    }
    cout << n-dp[1] << "\n";
    return 0;
}
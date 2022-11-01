#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=200000;
    vector<int> d[N+1];
    for(int i=1;i<=N;i++) for(int j=2*i;j<=N;j+=i) d[j].push_back(i);
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> freq(N+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            freq[a]++;
        }
        vector<int> sum(N+1,0);
        for(int i=1;i<=N;i++) sum[i]=sum[i-1]+freq[i];
        auto s=[&](int l,int r)->int{return (sum[r]-sum[l-1]);};
        vector<int> dp(N+1,n);
        dp[1]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j:d[i]) dp[i]=min(dp[i],dp[j]+s(j+1,i-1));
        }
        int res=n;
        for(int i=1;i<=N;i++) res=min(res,dp[i]+s(i+1,N));
        cout << res << "\n";
    }
    return 0;
}
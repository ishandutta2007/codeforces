#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000;
    vector<int> d(N+1,-1);
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int j=1;j<=a;j++)
        {
            if(a+a/j<=N&&d[a+a/j]==-1)
            {
                d[a+a/j]=d[a]+1;
                q.push(a+a/j);
            }
        }
    }
    int mx=0;
    for(int i=1;i<=N;i++) mx=max(mx,d[i]);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<int> dp(n*mx+1,0);
        for(int i=1;i<=n;i++)
        {
            int c;
            cin >> c;
            int s=d[b[i]];
            for(int j=n*mx-s;j>=0;j--) dp[j+s]=max(dp[j+s],dp[j]+c);
        }
        int res=0;
        for(int i=0;i<=min(n*mx,k);i++) res=max(res,dp[i]);
        cout << res << "\n";
    }
    return 0;
}
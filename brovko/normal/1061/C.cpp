#include <bits/stdc++.h>
//#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;
const int MOD=1000000007;

int n, a[100005], dp[100005];

int add(int x, int y)
{
    y+=x;
    while(y>=MOD)
        y-=MOD;
    while(y<0)
        y+=MOD;
    return y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp[0]=1;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            int x=sqrt(a[i]);
            for(int j=x;j>=1;j--)
                if(a[i]%j==0)
            {
                int y=a[i]/j;
                if(y<=n && y!=j)
                    dp[y]=add(dp[y], dp[y-1]);
                dp[j]=add(dp[j], dp[j-1]);
            }
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=add(ans, dp[i]);
    cout << ans;
}
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 100005

ll a[MAXN],b[MAXN],dp[MAXN][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=max(dp[i][1],max(dp[i][2],dp[i][0]));
        dp[i+1][1]=max(dp[i][0],dp[i][2])+a[i];
        dp[i+1][2]=max(dp[i][0],dp[i][1])+b[i];
    }

    db(max(dp[n][1],dp[n][2]))

    return 0;
}
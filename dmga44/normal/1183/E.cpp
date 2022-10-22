#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 105

int last[26];
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    string s;
    cin >> n >> k >> s;
    for(int i=0;i<26;i++)
        last[i]=-1;

    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        int p=s[i]-'a';
        for(int j=0;j<=n;j++)
        {
            dp[i+1][j]=dp[i][j];
            if(!j)
                continue;
            dp[i+1][j]+=dp[i][j-1];
            if(last[p]!=-1)
                dp[i+1][j]-=dp[last[p]][j-1];
        }
        last[p]=i;
    }

    ll res=0;
    for(ll i=0;i<=n;i++)
    {
        dp[n][n-i]=max(0ll,dp[n][n-i]);
        ll rrr=min(k,dp[n][n-i]);
        k-=rrr;
        res+=(rrr*i);
    }
    if(!k)
        db(res)
    else
        db(-1)

    return 0;
}
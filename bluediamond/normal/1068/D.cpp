#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
const ll MOD=998244353;

int n,v[N];
int lol=200;

ll dp[N][205][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    if(v[1]==-1)
    {
        for(int val=1;val<=lol;val++)
        {
            dp[1][val][0]=1;
        }
    }
    else
    {
        dp[1][v[1]][0]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(v[i]!=-1)
        {
            int val=v[i];
            /// dp[i][val][1]
            for(int ant=val;ant<=lol;ant++)
            {
                dp[i][val][1]+=dp[i-1][ant][1];
            }
            dp[i][val][1]+=dp[i-1][val][0];
            /// dp[i][val][0]
            for(int ant=1;ant<val;ant++)
            {
                dp[i][val][0]+=dp[i-1][ant][0];
                dp[i][val][0]+=dp[i-1][ant][1];
            }
            continue;
        }
        ll sum=0LL;
        for(int ant=1;ant<=lol;ant++)
        {
            sum+=dp[i-1][ant][1];
            sum%=MOD;
        }
        ll s2=0LL;
        for(int val=1;val<=lol;val++)
        {
            /// dp[i][val][1]
            dp[i][val][1]=sum;
            sum-=dp[i-1][val][1];
            sum%=MOD; sum+=MOD; sum%=MOD;
            dp[i][val][1]+=dp[i-1][val][0];
            dp[i][val][1]%=MOD;
            /// dp[i][val][0]
            dp[i][val][0]=s2;
            s2+=dp[i-1][val][0]; s2+=dp[i-1][val][1];
            s2%=MOD;
        }
    }
    ll ans=0LL;
    for(int val=1;val<=lol;val++)
    {
        ans+=dp[n][val][1];
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<ll> prime;
bool p[1000002];
ll dp[1000002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ll sum = 1;
    for(int i=1;i<=n;i++) p[i] = 1;
    p[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(p[i])
        {
            for(int j=i*2;j<=n;j+=i)
            {
                p[j] = 0;
            }
            prime.push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i] = sum;
        int j = i;
        ll tmp = 1; int k = 0;
        while(j>1 && p[j] == 0)
        {
            ll cnt = 0;
            while(j%prime[k] == 0)
            {
                j /= prime[k];
                cnt++;
            }
            tmp *= cnt+1;
            k++;
        }
        if(j != 1) tmp *= 2;

        tmp--;
        dp[i] += tmp;
        dp[i] %= mod;
        sum += dp[i];
        sum %= mod;
    }

    cout << dp[n];
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;
const int N = 1e7 + 5;

int n, a[100005], k[N], lp[N];
li dp[N], dp2[N];
vector <int> primes[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < N; i++)
        if(lp[i] == 0)
        {
            lp[i] = i;

            for(int j = i * i; j < N; j += i)
                if(lp[j] == 0)
                    lp[j] = i;
        }

    for(int i = 2; i < N; i++)
    {
        int x = i / lp[i];
        primes[i] = primes[x];

        if(lp[i] != lp[x])
            primes[i].pb(lp[i]);
    }

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        k[a[i]]++;

    for(int i = 1; i < N; i++)
        for(int j = i + i; j < N; j += i)
            k[i] += k[j];

    li ans = 0;

//    for(auto x:primes[60])
//        cout << x << ' ';
//
//    cout << "\n";

    for(int i = 1; i < N; i++)
    {
        for(auto p:primes[i])
        {
            int del = i / p;
            dp[i] = max(dp[i], dp[del] + del * 1ll * (k[del] - k[i]));
            dp[i] = max(dp[i], dp2[del]);
            dp2[i] = max(dp2[i], dp2[del]);
        }

        dp2[i] = max(dp2[i], dp[i]);
        ans = max(ans, dp[i]);
        ans = max(ans, dp2[i]);

//        if(i <= 15)
//            cout << dp[i] << ' ';
    }

//    cout << endl;

    cout << ans;
}
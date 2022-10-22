#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 1e9 + 7;

int dp[40005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;

    for(int i = 1; i < 40005; i++)
    {
        int x = i;

        vector <int> v;

        while(x)
        {
            v.pb(x % 10);
            x /= 10;
        }

        vector <int> u = v;
        reverse(u.begin(), u.end());

        if(u == v)
        {
            for(int j = i; j < 40005; j++)
                dp[j] = add(dp[j], dp[j - i]);
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }
}
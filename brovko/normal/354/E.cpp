#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

using li = long long;

map <int, int> dp;
vector <bool> good(100);

int f(int x)
{
    if(dp.count(x))
        return dp[x];

    if(x == 0)
        return 0;

    if(x < 0)
        return -1;

    for(int i = 0; i < 5; i++)
        if(good[x % 10 + i * 10] && f(x / 10 - i) != -1)
            dp[x] = f(x / 10 - i) * 10 + i;

    if(!dp.count(x))
        dp[x] = -1;

    return dp[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[100] = {};

    for(int i = 1; i < 100; i++)
    {
        dp[i] = 1e9;

        if(i - 4 >= 0)
            dp[i] = min(dp[i], dp[i - 4] + 1);

        if(i - 7 >= 0)
            dp[i] = min(dp[i], dp[i - 7] + 1);
    }

    for(int i = 0; i < 100; i++)
        if(dp[i] < 7)
            good[i] = 1;

    int t;
    cin >> t;

    while(t--)
    {
        li n;
        cin >> n;

        int val = f(n);

        if(val == -1)
        {
            cout << "-1\n";
            continue;
        }

        vector <int> ans(6);

//        cout << "val " << val << endl;

        int p = 1;

        while(n > 0)
        {
            int c = n % 10 + val % 10 * 10;

//            cout << c << endl;

            while(c > 0)
            {
                if(dp[c - 7] == dp[c] - 1)
                {
                    ans[dp[c] - 1] += p * 7;
                    c -= 7;
                }
                else
                {
                    ans[dp[c] - 1] += p * 4;
                    c -= 4;
                }
            }

            n /= 10;
            n -= val % 10;
            val /= 10;

            p *= 10;
        }

        for(auto x:ans)
            cout << x << ' ';

        cout << "\n";
    }
}
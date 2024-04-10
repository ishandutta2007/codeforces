#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;
const int N = 1e3 + 5;
const int M = 5e5 + 5;

int dp[M];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 0;

    for(int i = 1; i < N; i++)
    {
        int used[1005] = {};

        for(int j = 0; j <= i - 2; j++)
            used[dp[j] ^ dp[i - j - 2]] = 1;

        dp[i] = 0;

        while(used[dp[i]])
            dp[i]++;
    }

    for(int i = N; i < M; i++)
        dp[i] = dp[i - 154 + 86];

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int b = 0;

        for(int i = 0; i < n; i++)
            b += (s[i] == 'R') - (s[i] == 'B');

        if(b > 0)
            cout << "Alice\n";
        else if(b < 0)
            cout << "Bob\n";
        else
        {
            int ans = 0;
            int k = 0;

            for(int i = 0; i < n; i++)
            {
                if(i == 0 || s[i] != s[i - 1])
                    k++;
                else
                {
                    ans ^= dp[k];
                    k = 1;
                }
            }

            ans ^= dp[k];

            cout << (ans == 0 ? "Bob" : "Alice") << "\n";
        }
    }
}
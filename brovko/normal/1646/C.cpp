#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, fact[20];

int pop(int N)
{
    int s = 0;

    while(N)
    {
        s += N % 2;
        N /= 2;
    }

    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 20; i++)
        fact[i] = fact[i - 1] * i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        int ans = 1e9;

        for(int mask = 0; mask < (1 << 15); mask += 4)
        {
            if(__builtin_popcount(mask) >= ans)
                continue;

            int N = n;

            for(int i = 2; i <= 14; i++)
                if(mask & (1 << i))
                    N -= fact[i];

            if(N >= 0)
                ans = min(ans, 1ll * __builtin_popcount(mask * 1ll) + pop(N));
        }

        cout << (ans > 1e8 ? -1 : ans) << "\n";
    }
}
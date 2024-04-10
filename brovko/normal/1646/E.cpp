#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, used[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int ans = 1;

    for(int i = 2; i <= n; i++)
        if(used[i] == 0)
        {
            used[i] = 1;
            vector <int> v;

            for(int j = i; j <= n; j *= i)
            {
                used[j] = 1;
                v.pb(j);
            }

            int k = v.size();

            for(int mask = 1; mask < (1 << k); mask++)
            {
                int L = 1, a1 = 0;

                for(int i = 0; i < k; i++)
                    if(mask & (1 << i))
                    {
                        if(a1 == 0)
                            a1 = i + 1;

                        L = min((int)2e12, L * (i + 1) / __gcd(L, i + 1));
                    }

                if(__builtin_popcount(mask) % 2)
                    ans += a1 * m / L;
                else ans -= a1 * m / L;
            }
        }

    cout << ans;
}
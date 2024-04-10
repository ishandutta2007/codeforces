#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = 0;

        for(int i = 30; i >= 0; i--)
        {
            if(k & (1 << i))
                ans = (ans * n + 1) % MOD;
            else ans = ans * n % MOD;
        }

        cout << ans << "\n";
    }
}
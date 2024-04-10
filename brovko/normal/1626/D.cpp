#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], ps[200005];

int f(int x)
{
    int k = 0;

    while(x > (1 << k))
        k++;

    return (1 << k) - x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        vector <int> v;

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || a[i] == a[i - 1])
            {
                x++;
            }
            else
            {
                v.pb(x);
                x = 1;
            }
        }

        v.pb(x);

        int ans = 1e18;

        n = v.size();

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + v[i];

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                int L = 0, R = n + 1;

                while(R - L > 1)
                {
                    int M = (L + R) / 2;

                    if(ps[M] <= ps[i] + (1 << j))
                        L = M;
                    else R = M;
                }

                int A = ps[i], B = ps[L] - A, C = ps[n] - A - B;

                ans = min(ans, f(A) + f(B) + f(C));
            }
        }

        cout << ans << "\n";
    }
}
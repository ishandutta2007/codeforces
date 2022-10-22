#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005];

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

        map <int, int> m;

        for(int i = 0; i < n; i++)
            m[a[i]]++;

        int ans2 = 0;

        for(int i = 0; i < n; i++)
        {
            int ans = m[a[i]];

            int d = 1, x = i;

            while(a[n - 1] - a[i] >= d)
            {
                int L = x, R = n - 1;

                while(R - L > 1)
                {
                    int M = (L + R) / 2;

                    if(a[M] - a[i] >= d)
                        R = M;
                    else L = M;
                }

                x = R;
                ans++;
                d = 2 * (a[R] - a[i]);
            }

            ans2 = max(ans2, ans);
        }

        cout << n - ans2 << "\n";
    }
}
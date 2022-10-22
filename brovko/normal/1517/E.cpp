#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
const int MOD = 998244353;

int t, n, a[200005], ps[200005], ps2[200005];

int add(int x, int y)
{
    return (x + y) % MOD;
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

        ps[0] = 0;

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        ps2[0] = 0;
        ps2[1] = 0;

        for(int i = 0; i < n; i++)
            ps2[i + 2] = ps2[i] + a[i];

        int ans = 0;

        for(int i = 0; i <= n; i++)
            if(ps[i] > ps[n] - ps[i])
                ans = add(ans, 1);

        //cout << ans << endl;

        for(int L = 0; L <= 1; L++)
            for(int R = n - 2; R <= n - 1; R++)
            {
                for(int i = L; i < R; i++)
                {
                    int l = i - 1, r = R;

                    while(r - l > 1)
                    {
                        int m = (l + r) / 2;
                        int rc = ((m - i) / 2 * 2) + i;

                        int sc = ps2[rc + 2] - ps2[i + 2] + ps[i + 1] - ps[L];

                        if(R == n - 2)
                            sc += a[n - 1];

                        int sp = ps[n] - sc;

                        //cout << m << ' ' << sc << ' ' << sp << ' ' << rc << endl;

                        if(sc < sp)
                            l = m;
                        else r = m;
                    }

                    ans = add(ans, (l - i + 2) / 2);
                    //cout << l << endl;
                }

                //cout << ans << endl;
            }

        cout << ans << "\n";
    }
}

/*

1
5
2 1 2 1 1

*/
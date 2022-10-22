#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, a[200005], b[200005], ps[200005], c[200005], d[200005], N, M;

int solve()
{
    for(int i = 0; i <= n; i++)
        ps[i] = 0;

    int ans = 0;

    map <int, int> used;

    for(int i = 0; i < m; i++)
        used[b[i]] = 1;

    ps[0] = 0;

    for(int i = 0; i < n; i++)
        if(used[a[i]])
            ps[i + 1] = ps[i] + 1;
        else ps[i + 1] = ps[i];

    for(int j = 0; j < m; j++)
    {
        int L = -1;
        int R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(b[j] + M >= a[M])
                L = M;
            else R = M;
        }

        int l = -1;
        int r = m;

        while(r - l > 1)
        {
            int m = (l + r) / 2;

            if(b[m] <= b[j] + L)
                l = m;
            else r = m;
        }

        ans = max(ans, l - j + 1 + ps[n] - ps[L + 1]);

        //cout << L << ' ' << l << endl;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> N >> M;

        for(int i = 0; i < N; i++)
            cin >> c[i];

        for(int i = 0; i < M; i++)
            cin >> d[i];

        n = 0;
        m = 0;

        for(int i = 0; i < N; i++)
        {
            if(c[i] > 0)
            {
                a[n] = c[i];
                n++;
            }
        }

        for(int i = 0; i < M; i++)
        {
            if(d[i] > 0)
            {
                b[m] = d[i];
                m++;
            }
        }

        int ans = solve();


        n = 0;
        m = 0;

        for(int i = N - 1; i >= 0; i--)
        {
            if(c[i] < 0)
            {
                a[n] = -c[i];
                n++;
            }
        }

        for(int i = M - 1; i >= 0; i--)
        {
            if(d[i] < 0)
            {
                b[m] = -d[i];
                m++;
            }
        }

        ans += solve();

        cout << ans << "\n";
    }
}

/*
1
4 3
1 5 11 15
6 7 15

*/
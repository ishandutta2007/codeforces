#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, a[200005];

bool f(int cnt)
{
    int L = -1, R = cnt, ans = 1e18;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int Min = a[0] - M, s1 = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || i + cnt - M >= n)
                s1 += Min;
            else s1 += a[i];
        }

        Min--;
        int s2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || i + cnt - M - 1 >= n)
                s2 += Min;
            else s2 += a[i];
        }

        ans = min({ans, s1, s2});

        if(s1 > s2)
            L = M;
        else R = M;
    }

    return (ans <= k);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        if(s <= k)
        {
            cout << "0\n";
            continue;
        }

        int L = -1, R = 2e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(f(M))
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[500005], t[500005], b[500005];

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= n; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while(q--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i <= n; i++)
        {
            b[i] = 0;
            t[i] = 0;
        }

        int F = 1, ans = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            ans += sum(a[i]);

            b[a[i]]++;
            inc(a[i], 1);

            if(b[a[i]] >= 2)
                F = 0;
        }

        if(ans % 2 == 0 || F == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
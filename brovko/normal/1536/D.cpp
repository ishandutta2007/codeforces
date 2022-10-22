#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[200005], T[200005];

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += T[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= n; i = (i | i + 1))
        T[i] += d;
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

        map <int, int> m;
        vector <int> v;

        for(int i = 0; i < n; i++)
            v.pb(a[i]);

        sort(v.begin(), v.end());

        int y = 0;

        for(int i = 0; i < n; i++)
            if(m[v[i]] == 0)
            {
                y++;
                m[v[i]] = y;
            }

        for(int i = 0; i < n; i++)
            a[i] = m[a[i]];

        for(int i = 0; i <= n; i++)
            T[i] = 0;

        for(int i = 0; i < n; i++)
            inc(a[i], 1);

        int f = 1;

        for(int i = n - 1; i >= 1; i--)
        {
            if(sum(max(a[i], a[i - 1]) - 1) - sum(min(a[i], a[i - 1])) > 0)
            {
                f = 0;
            }

            inc(a[i], -1);
        }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
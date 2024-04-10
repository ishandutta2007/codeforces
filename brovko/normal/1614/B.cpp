#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005];

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

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
        {
            v.pb({a[i], i});
        }

        sort(v.rbegin(), v.rend());

        int l = -1, r = 1, ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(abs(l) < abs(r))
            {
                b[v[i].y] = l;
                l--;
            }
            else
            {
                b[v[i].y] = r;
                r++;
            }

            ans += 2 * v[i].x * abs(b[v[i].y]);
        }

        cout << ans << "\n" << "0 ";

        for(int i = 0; i < n; i++)
            cout << b[i] << ' ';

        cout << "\n";
    }
}
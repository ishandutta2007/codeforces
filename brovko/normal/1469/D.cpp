#include <bits/stdc++.h>
#define ld long double
#define int long long

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
        vector <pair <int, int> > v;

        for(int i = 1; i <= n; i++)
            a[i] = i;

        for(int i = n - 1; i >= 2; i--)
        {
            while((a[n] + i - 1) / i >= i)
            {
                a[n] = (a[n] + i - 1) / i;
                v.push_back({n, i});
            }

            a[i] = 1;
            v.push_back({i, n});
        }

        cout << v.size() << "\n";

        for(auto to:v)
            cout << to.first << ' ' << to.second << "\n";
    }
}
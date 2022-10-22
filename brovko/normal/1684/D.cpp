#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({-i - a[i], i});

        sort(v.begin(), v.end());

        for(int i = 0; i < k; i++)
            a[v[i].y] = -1;

        int ans = 0, c = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == -1)
                c++;
            else ans += a[i] + c;
        }

        cout << ans << "\n";
    }
}
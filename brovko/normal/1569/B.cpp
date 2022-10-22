#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n;
char a[55], ans[55][55];

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

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(a[i] == '2')
                v.pb(i);

        if(v.size() > 0 && v.size() < 3)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = '=';

        for(int i = 0; i < n; i++)
            ans[i][i] = 'X';

        for(int i = 1; i <= v.size(); i++)
        {
            ans[v[i % v.size()]][v[i - 1]] = '+';
            ans[v[i - 1]][v[i % v.size()]] = '-';
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << ans[i][j];

            cout << "\n";
        }
    }
}
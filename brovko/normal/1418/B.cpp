#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[105], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> b[i];

            if(b[i] == 0)
                v.pb(a[i]);
        }

        sort(v.rbegin(), v.rend());

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(b[i] == 0)
            {
                cout << v[x] << ' ';
                x++;
            }
            else cout << a[i] << ' ';
        }

        cout << "\n";
    }
}
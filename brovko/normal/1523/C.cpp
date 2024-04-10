#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[1005];

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
        {
            if(a[i] == 1)
                v.pb(1);
            else
            {
                while(v[v.size() - 1] != a[i] - 1)
                    v.pop_back();

                v[v.size() - 1]++;
            }

            for(int i = 0; i < v.size() - 1; i++)
                cout << v[i] << '.';

            cout << v[v.size() - 1] << "\n";
        }
    }
}
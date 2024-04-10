#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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
        int n;
        cin >> n;

        int x = 1;

        vector <int> v;

        while(v.size() < n && x <= 1e9)
        {
            v.pb(x);
            x *= 3;
        }

        if(v.size() == n)
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
                cout << v[i] << ' ';

            cout << "\n";
        }
        else cout << "NO\n";
    }
}
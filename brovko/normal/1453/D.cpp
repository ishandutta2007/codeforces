#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k;

        if(k % 2)
        {
            cout << "-1\n";
            continue;
        }

        vector <int> v;

        v.pb(1);
        k -= 2;

        for(int i = 60; i >= 1; i--)
        {
            while(k >= (1ll << i + 1) - 2)
            {
                k -= (1ll << i + 1) - 2;

                for(int j = 0; j < i - 1; j++)
                    v.pb(0);

                v.pb(1);
            }
        }

        cout << v.size() << "\n";

        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}
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

        int k0 = 0, k1 = 0;

        for(int i = 0; i < n; i++)
            if(a[i] == 0)
                k0++;
            else k1++;


        vector <int> v;

        if(k1 <= n / 2)
        {
            for(int i = 0; i < n; i++)
                if(a[i] == 0)
                    v.pb(a[i]);
        }
        else
        {
            int f = 0;

            for(int i = 0; i < n; i++)
            {
                if(a[i] == 1)
                {
                    if(f == 0 && k1 % 2 != 0)
                        f = 1;
                    else v.pb(a[i]);
                }
            }
        }

        cout << v.size() << "\n";

        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}
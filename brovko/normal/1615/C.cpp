#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;
string a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        int ka = 0, kb = 0;

        for(auto x:a)
            ka += x - '0';

        for(auto x:b)
            kb += x - '0';

        int Min = 1e9;

        if(ka == kb)
        {
            int c = 0;

            for(int i = 0; i < n; i++)
                if(a[i] != b[i])
                    c++;

            Min = min(Min, c);
        }

        if(n - ka + 1 == kb)
        {
            int c = 0;

            for(int i = 0; i < n; i++)
                if(a[i] == b[i])
                    c++;

            Min = min(Min, max(1ll, c));
        }

        if(Min >= 1e8)
            cout << "-1\n";
        else cout << Min << "\n";
    }
}
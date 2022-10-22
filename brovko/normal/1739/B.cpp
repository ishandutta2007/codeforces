#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        li s = 0;
        bool F = 1;

        vector <int> ans;

        for(int i = 0; i < n; i++)
        {
            if(a[i] && s >= a[i])
                F = 0;

            s += a[i];
            ans.pb(s);
        }

        if(!F)
        {
            cout << "-1\n";
            continue;
        }

        for(auto x:ans)
            cout << x << ' ';

        cout << "\n";
    }
}
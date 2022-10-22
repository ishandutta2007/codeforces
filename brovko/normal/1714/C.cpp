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
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int s;
        cin >> s;

        vector <int> v;

        while(s > 0)
        {
            int x = min(s, (v.size() == 0 ? 9 : v.back() - 1));
            v.pb(x);
            s -= x;
        }

        reverse(v.begin(), v.end());

        for(auto x:v)
            cout << x;

        cout << "\n";
    }
}
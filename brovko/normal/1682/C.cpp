#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector <int> b;

        for(int i = 0; i < n; i++)
        {
            if(b.size() < 2 || b[b.size() - 2] != a[i])
                b.pb(a[i]);
        }

        cout << (b.size() + 1) / 2 << "\n";
    }
}
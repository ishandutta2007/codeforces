#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back


using namespace std;

int t, n, a[100005];

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

        vector <int> e, o;

        for(int i = 0; i < n; i++)
            if(a[i] % 2 == 0)
                e.pb(a[i]);
            else o.pb(a[i]);

        vector <int> e2 = e, o2 = o;

        sort(e2.begin(), e2.end());
        sort(o2.begin(), o2.end());

        if(e == e2 && o == o2)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
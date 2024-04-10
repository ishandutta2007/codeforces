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

        sort(a, a + n);

        bool F1 = 0, F0 = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0 || a[i] == 2 || i > 0 && a[i] == a[i - 1] + 1)
                F0 = 1;

            if(a[i] == 1)
                F1 = 1;
        }

        if(!F0 || !F1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
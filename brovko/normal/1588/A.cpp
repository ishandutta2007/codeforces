#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[105], b[105];

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

        for(int i = 0; i < n; i++)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + n);

        int F = 1;

        for(int i = 0; i < n; i++)
            if(b[i] != a[i] && b[i] != a[i] + 1)
                F = 0;

        if(F)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
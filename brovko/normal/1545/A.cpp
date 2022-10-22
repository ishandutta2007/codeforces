#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[200005], k[200005];

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
            k[a[i]] = 0;

        for(int i = 0; i < n; i += 2)
            k[a[i]]++;

        sort(a, a + n);

        for(int i = 0; i < n; i += 2)
            k[a[i]]--;

        int f = 1;

        for(int i = 0; i < n; i++)
            if(k[a[i]])
                f = 0;

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
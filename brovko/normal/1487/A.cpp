#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[105];

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

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] == a[0])
                k++;

        cout << n - k << "\n";
    }
}
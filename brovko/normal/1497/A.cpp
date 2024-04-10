#include <bits/stdc++.h>
#define int long long
#define ld long double

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

        for(int i = 0; i < 105; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
            b[a[i]]++;

        int j = 0;

        while(b[j])
        {
            b[j]--;
            cout << j << ' ';
            j++;
        }

        for(int i = 0; i < 105; i++)
            for(int j = 0; j < b[i]; j++)
                cout << i << ' ';

        cout << "\n";
    }
}
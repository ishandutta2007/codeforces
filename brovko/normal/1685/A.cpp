#include <bits/stdc++.h>
#define int long long

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

        if(n % 2)
        {
            cout << "NO\n";
            continue;
        }

        sort(a.begin(), a.end());

        vector <int> b;

        b.push_back(a[n - 1]);

        for(int i = 0; i < n / 2; i++)
        {
            b.push_back(a[i]);
            b.push_back(a[n / 2 + i]);
        }

        b.push_back(a[0]);

        bool F = 1;

        for(int i = 1; i <= n; i++)
        {
            if(b[i] == b[i + 1] || b[i] == b[i - 1] || ((b[i] > b[i + 1]) == (b[i - 1] > b[i])))
                F = 0;
        }

        if(!F)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            for(int i = 1; i <= n; i++)
                cout << b[i] << ' ';

            cout << "\n";
        }
    }
}
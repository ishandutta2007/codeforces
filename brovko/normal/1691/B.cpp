#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

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

        vector <int> p(n);

        int last = 0;
        bool F = true;

        for(int i = 0; i < n; i++)
        {
            if(i == n - 1 || a[i] != a[i + 1])
            {
                p[i] = last;
                last = i + 1;

                if(i == 0 || a[i] != a[i - 1])
                    F = false;
            }
            else p[i] = i + 1;
        }

        if(!F)
            cout << "-1\n";
        else
        {
            for(int i = 0; i < n; i++)
                cout << p[i] + 1 << ' ';

            cout << "\n";
        }
    }
}
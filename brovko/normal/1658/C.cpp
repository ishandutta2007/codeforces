#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, c[100005];

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
            cin >> c[i];

        int Min = 0, k = 0;

        for(int i = 0; i < n; i++)
            if(c[i] == 1)
            {
                Min = i;
                k++;
            }

        if(k != 1)
        {
            cout << "NO\n";
            continue;
        }

        bool F = 1;

        for(int i = 0; i < n; i++)
            if(c[(i + 1) % n] - c[i] >= 2)
                F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}
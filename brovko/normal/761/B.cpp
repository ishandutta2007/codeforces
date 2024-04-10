#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, a[55], b[55], c[55], d[55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
    {
        c[i] = (a[(i + 1) % n] - a[i] + l) % l;
        d[i] = (b[(i + 1) % n] - b[i] + l) % l;
    }

    for(int i = 0; i < n; i++)
    {
        int f = 1;

        for(int j = 0; j < n; j++)
        {
            if(c[j] != d[(j + i) % n])
                f = 0;
        }

        if(f)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
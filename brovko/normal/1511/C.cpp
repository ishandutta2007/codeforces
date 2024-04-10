#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, q, a[300005], b[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int N = 300001;

    b[N] = 0;

    for(int i = 1; i < n; i++)
        b[i - 1] = i;

    while(q--)
    {
        int t;
        cin >> t;

        int x = N, y = 0, z = N;

        while(a[x] != t)
        {
            z = x;
            x = b[x];
            y++;
        }

        cout << y << ' ';

        b[z] = b[x];
        b[x] = b[N];
        b[N] = x;
    }
}
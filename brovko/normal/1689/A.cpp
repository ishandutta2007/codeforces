#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        string c;

        int x = 0, y = 0, kx = 0, ky = 0;

        while(x < n && y < m)
        {
            if(ky == k || kx < k && a[x] < b[y])
            {
                c += a[x];
                x++;
                kx++;
                ky = 0;
            }
            else
            {
                c += b[y];
                y++;
                ky++;
                kx = 0;
            }
        }

        cout << c << "\n";
    }
}
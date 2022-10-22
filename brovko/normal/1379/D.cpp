#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, h, m, k, x, a[200005], b[200005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> m >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> a[i];
        a[i] %= m / 2;
        b[i] = a[i];
    }

    for(int i = 0; i < n; i++)
        a[n + i] = a[i] + m / 2;

    sort(a, a + 2 * n);

    int ans = 1e9, y = 0;

    for(int i = 0; i < n; i++)
    {
        int L = i;
        int R = n * 2;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(a[M] < a[i] + k)
                L = M;
            else R = M;
        }

        int z = L - i;

        if(z < ans)
        {
            y = a[i];
            ans = z;
        }
    }

    vector <int> u;

    for(int i = 0; i < n; i++)
    {
        if(b[i] > y && b[i] < y + k || b[i] + m / 2 > y && b[i] + m / 2 < y + k)
            u.push_back(i + 1);
    }

    cout << u.size() << ' ' << (y + k) % (m / 2) << "\n";

    for(auto to:u)
        cout << to << ' ';
}
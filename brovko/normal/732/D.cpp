#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[100005], b[100005], used[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < m; i++)
        cin >> b[i];

    int L = -1;
    int R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int x = 0;

        for(int i = 0; i < m; i++)
            used[i] = 0;

        for(int i = M; i >= 0; i--)
        {
            if(a[i] != -1 && used[a[i]] == 0)
            {
                used[a[i]] = 1;
                x += b[a[i]];
            }
            else if(x > 0)
                    x--;
        }

        int f = 0;

        for(int i = 0; i < m; i++)
            if(used[i] == 0)
                f = 1;

        if(f == 1 || x > 0)
            L = M;
        else R = M;
    }

    if(R == n)
        cout << -1;
    else cout << R + 1;
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, used[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            used[i] = 0;

        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            a--;
            b--;
            c--;

            used[b]++;
        }

        int x = 0;

        while(used[x])
            x++;

        for(int i = 0; i < n; i++)
            if(i != x)
                cout << i + 1 << ' ' << x + 1 << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int r[3], c[3];

        for(int i = 0; i < 3; i++)
            cin >> r[i] >> c[i];

        int x, y;
        cin >> x >> y;

        int px = (r[0] % 2 ^ r[1] % 2 ^ r[2] % 2);
        int py = (c[0] % 2 ^ c[1] % 2 ^ c[2] % 2);

        bool F = 1;

        if(x % 2 == px && y % 2 == py)
            F = 0;

        for(int i = 0; i < 3; i++)
        {
            if((r[i] == 1 && c[i] == 1 || r[i] == n && c[i] == 1 || r[i] == 1 && c[i] == n || r[i] == n && c[i] == n) && px != r[i] % 2 && py != c[i] % 2 && x != r[i] && y != c[i])
                F = 0;
        }

        for(int i = 0; i < 3; i++)
            if(r[i] == x && c[i] == y)
                F = 1;

        cout << (F ? "YES\n" : "NO\n");
    }
}
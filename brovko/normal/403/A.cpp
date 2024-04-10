#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, p, used[30][30];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> p;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                used[i][j] = 0;

        for(int i = 0; i < n; i++)
        {
            used[i][(i + 1) % n] = 1;
            used[i][(i + 2) % n] = 1;
            used[(i + 1) % n][i] = 1;
            used[(i + 2) % n][i] = 1;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && used[i][j] == 0 && p > 0)
                {
                    p--;
                    used[i][j] = 1;
                    used[j][i] = 1;
                }

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(used[i][j])
                    cout << i + 1 << ' ' << j + 1 << "\n";
    }
}
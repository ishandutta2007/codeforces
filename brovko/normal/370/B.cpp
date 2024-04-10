#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m[105], a[105][105], used[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> m[i];

        for(int j = 0; j < m[i]; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 100; j++)
            used[j] = 0;

        for(int j = 0; j < m[i]; j++)
            used[a[i][j]] = 1;

        int F = 1;

        for(int j = 0; j < n; j++)
            if(j != i)
            {
                int f = 0;

                for(int z = 0; z < m[j]; z++)
                    f += (used[a[j][z]] == 0);

                if(f == 0)
                    F = 0;
            }

        if(F)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
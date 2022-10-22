#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        int Max = 0;

        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            Max = max(Max, a[i][j]);
        }

        if(Max == n - 1)
        {
            x = i;
        }
    }

    for(int j = 0; j < n; j++)
        if(a[x][j] == 0)
            cout << n << ' ';
        else cout << a[x][j] << ' ';
}
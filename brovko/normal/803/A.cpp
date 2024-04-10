#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if(k > n * n)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
    {
        if(i == j && k >= 1)
        {
            k--;
            a[i][j] = 1;
        }

        if(i != j && k >= 2)
        {
            k -= 2;
            a[i][j] = 1;
            a[j][i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i][i] == 0 && k > 0)
        {
            k--;
            a[i][i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << "\n";
    }
}
#include <bits/stdc++.h>
//#define int long long
#define ld long double
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

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    int k[n + 1][5];

    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < 5; j++)
            k[i][j] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
            k[i + 1][j] = k[i][j] + (a[i] == j);
    }

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    int ans = 1e9;

    for(int k4 = 0; k4 * 4 <= s; k4++)
    {
        if((s - 4 * k4) % 3)
            continue;

        int k3 = (s - 4 * k4) / 3;

        if(k3 + k4 > n)
            continue;

        int x = 0;

        for(int j = 0; j < 5; j++)
            x += k[k4][j] * abs(j - 4) + (k[k4 + k3][j] - k[k4][j]) * abs(j - 3) + (k[n][j] - k[k4 + k3][j]) * j;

        ans = min(ans, x);
    }

    cout << (ans > 1e8 ? -1 : ans / 2);
}
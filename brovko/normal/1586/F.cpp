#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, c[1005][1005], Max;

void rec(int l, int r, int col)
{
    if(r - l <= 1)
        return;

    Max = max(Max, col);

    int d = (r - l + k - 1) / k;

    for(int i = l; i < r; i++)
        for(int j = (i - l) / d * d + d + l; j < r; j++)
            c[i][j] = col;

    for(int i = l; i < r; i += d)
        rec(i, min(r, i + d), col + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    rec(0, n, 1);

    cout << Max << "\n";

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            cout << c[i][j] << ' ';
}
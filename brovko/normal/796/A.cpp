#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    m--;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int Min = 1e9;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0 && a[i] <= k)
            Min = min(Min, abs(m - i));
    }

    cout << Min * 10;
}
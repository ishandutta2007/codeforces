#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, d, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int Min = 1e9;

    for(int i = 0; i < n; i++)
    {
        int l = a[i];
        for(int j = i; j < n; j++)
        {
            int r = a[j];
            if(r - l <= d)
                Min = min(Min, n - (j - i + 1));
        }
    }

    cout << Min;
}
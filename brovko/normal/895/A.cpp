#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[365];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int Min = 1e9;

    for(int i=0; i<n; i++)
    {
        int s = 0;

        for(int j=i; j<n; j++)
        {
            s += a[j];
            Min = min(Min, abs(360 - 2 * s));
        }
    }
    cout << Min;
}
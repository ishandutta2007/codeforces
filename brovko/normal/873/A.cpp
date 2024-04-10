#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, x, a[105], s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        if(i >= n - k)
            s += x;
        else s += a[i];
    }

    cout << s;
}
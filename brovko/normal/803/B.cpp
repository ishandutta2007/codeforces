#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], l[200005], r[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        l[i] = -1e9;
        r[i] = 1e9;
    }

    int x = -1e9;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
            x = i;
        l[i] = x;
    }

    x = 1e9;

    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == 0)
            x = i;
        r[i] = x;
    }

    for(int i = 0; i < n; i++)
        cout << min(i - l[i], r[i] - i) << ' ';
}
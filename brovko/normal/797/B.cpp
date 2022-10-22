#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;
    int Max = -1e9;
    int Min = 1e9;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
            s += a[i];

        if(a[i] < 0 && a[i] % 2 != 0)
            Max = max(Max, a[i]);

        if(a[i] > 0 && a[i] % 2 != 0)
            Min = min(Min, a[i]);
    }

    if(s % 2)
        cout << s;
    else cout << s - min(Min, -Max);
}
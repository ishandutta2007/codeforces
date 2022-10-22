#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, r, s, Max, Min;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    Max = -1e9;
    Min = 1e9;

    int Max1 = 0, Min1 = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;

        s += l - r;
        Max = max(Max, l - r);
        Min = min(Min, l - r);

        if(Max == l - r)
            Max1 = i;

        if(Min == l - r)
            Min1 = i;
    }
    
    if(abs(s) > abs(s - Max) && abs(s) > abs(s - Min))
    {
        cout << 0;
        return 0;
    }

    if(abs(s - Max * 2) > abs(s - Min * 2))
        cout << Max1 + 1;
    else cout << Min1 + 1;
}
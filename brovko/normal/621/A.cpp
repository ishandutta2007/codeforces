#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

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

    int knc = 0, Min = 1e9;

    for(int i = 0; i < n; i++)
        if(a[i] % 2)
    {
        knc++;
        Min = min(Min, a[i]);
    }

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    if(knc % 2 == 0)
        cout << s;
    else cout << s - Min;
}
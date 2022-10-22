#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[100005];
map <int, int> m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;
    int Max = 0;

    for(int i = 0; i < n; i++)
    {
        s += a[i];

        m[s]++;

        Max = max(Max, m[s]);
    }

    cout << n - Max;
}
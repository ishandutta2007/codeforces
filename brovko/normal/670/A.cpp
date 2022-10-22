#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int k1 = 0, k2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(i % 7 == 0 || i % 7 == 1)
            k2++;

        if(i % 7 == 5 || i % 7 == 6)
            k1++;
    }

    cout << k1 << ' ' << k2;
}
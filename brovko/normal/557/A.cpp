#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, min1, max1, min2, max2, min3, max3;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;

    for(int i = max1; i >= min1; i--)
    {
        int j = max2;

        if(n - i - j >= min3 && n - i - j <= max3)
        {
            cout << i << ' ' << j << ' ' << n - i - j;
            return 0;
        }

        int k = min3;

        if(n - i - k >= min2 && n - i - k <= max2)
        {
            cout << i << ' ' << n - i - k << ' ' << k;
            return 0;
        }
    }
}
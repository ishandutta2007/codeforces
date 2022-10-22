#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int d(int x, int y)
{
    if(x % 10 + x / 10 % 10 + x / 100 % 10 != x / 1000 % 10 + x / 10000 % 10 + x / 100000)
        return 1e9;

    int k = 0;

    for(int i = 0; i < 6; i++)
    {
        if(x % 10 != y % 10)
            k++;

        x /= 10;
        y /= 10;
    }

    return k;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int Min = 1e9;

    for(int i = 0; i < 1000000; i++)
        Min = min(Min, d(i, n));

    cout << Min;
}
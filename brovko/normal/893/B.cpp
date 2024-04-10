#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x = 1;
    int y = 1;

    int Max = 1;

    for(int i=0; i<10; i++)
    {
        y += 2;
        x = x * 2 + (1ll << y - 1);

        if(n % x == 0)
            Max = max(Max, x);
    }

    cout << Max;
}
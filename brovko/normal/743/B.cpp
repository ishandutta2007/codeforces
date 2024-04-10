#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 55; i >= 0; i--)
    {
        if(k == (1ll << i))
        {
            cout << i + 1;
            return 0;
        }

        if(k > (1ll << i))
            k -= (1ll << i);
    }
}
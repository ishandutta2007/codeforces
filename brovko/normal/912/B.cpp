#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;

int f(int x)
{
    int k = 0;
    while(x)
    {
        x /= 2;
        k++;
    }

    return ((1ll << k) - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if(k == 1)
        cout << n;
    else cout << f(n);
}
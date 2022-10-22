#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, a[35];

int f(int x)
{
    if(x == 0)
        return 0;

    int y = 30;
    while(y >= n || (1ll << y) > x)
        y--;

    int Min = f(x % (1ll << y)) + a[y] * (x / (1ll << y));
    if(y < n - 1)
        Min = min(Min, a[y + 1]);
    return Min;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=n-1; i>0; i--)
        a[i-1] = min(a[i], a[i-1]);

    for(int i=0; i < n-1; i++)
        a[i + 1] = min(a[i + 1], 2 * a[i]);


    cout << f(l);

}
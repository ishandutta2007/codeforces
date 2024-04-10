#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, k1, k2, n;
    cin >> a >> b >> k1 >> k2 >> n;

    int x=a*(k1-1)+b*(k2-1);
    int y=max(0ll, n-x);

    if(k1>k2)
    {
        swap(a, b);
        swap(k1, k2);
    }

    int z=n/k1;
    if(z>a)
        z=a+(n-a*k1)/k2;
    cout << y << ' ' << z;
}
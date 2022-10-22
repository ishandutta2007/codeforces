#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, y, k1, k2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        if(x < 0)
            k1++;
        else k2++;
    }

    if(k1 <= 1 || k2 <= 1)
        cout << "Yes";
    else cout << "No";
}
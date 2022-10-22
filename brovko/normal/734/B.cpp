#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int k2, k3, k5, k6;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k2 >> k3 >> k5 >> k6;
    
    int x = min(k2, min(k5, k6));
    
    k2 -= x;
    
    int y = min(k2, k3);
    
    cout << x * 256 + y * 32;
}
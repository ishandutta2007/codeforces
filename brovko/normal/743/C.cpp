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
    
    if(n == 1)
        cout << -1;
    else cout << n << ' ' << n + 1 << ' ' << n * (n + 1);
}
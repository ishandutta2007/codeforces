#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int x=0;
    while(x*(x-1)/2<m)
        x++;
    cout << max(0ll, n-m*2) << ' ' << n-x;
}
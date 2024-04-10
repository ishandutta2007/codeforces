#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> l >> r;
    cout << "YES\n";
    for(int i=l;i<=r;i+=2)
        cout << i << ' ' << i+1 << "\n";
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> c >> d;
        if(c-d>(a+b)*n || c+d<(a-b)*n)
            cout << "No\n";
        else cout << "Yes\n";
    }
}
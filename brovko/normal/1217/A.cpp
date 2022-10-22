#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, s, i, e;

int f(int x)
{
    return (x+1000000000)/2-500000000;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s >> i >> e;
        cout << max(0ll, min(e+1, e-f(e-s+i))) << endl;
    }
}
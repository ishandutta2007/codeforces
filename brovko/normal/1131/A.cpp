#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int w1, h1, w2, h2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> w1 >> h1 >> w2 >> h2;
    cout << 2*h2+(w1+2)*(h1+2)-w1*h1;
}
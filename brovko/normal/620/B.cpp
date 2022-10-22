#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int x, y;
    cin >> x >> y;

    int ans = 0;

    for(int i = x; i <= y; i++)
    {
        int z = i;

        while(z > 0)
        {
            ans += a[z % 10];
            z /= 10;
        }
    }

    cout << ans;
}
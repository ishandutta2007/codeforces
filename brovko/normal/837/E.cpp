#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x, y;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;

    int z = x;

    for(int i = 2; i * i <= x; i++)
        while(x % i == 0)
    {
        x /= i;
        v.push_back(i);
    }

    if(x > 1)
        v.push_back(x);

    v.push_back(1e18);

    x = z;

    int ans = 0;

    while(y)
    {
        int Min = 1e18;
        int p = 0;

        for(int i = 0; i < v.size(); i++)
            {
                if(y % v[i] < Min)
                {
                    Min = y % v[i];
                    p = i;
                }
            }

        ans += Min;
        y -= Min;

        if(y)
        {
            x /= v[p];
            y /= v[p];
        }

        //cout << x << ' ' << y << endl;

        v[p] = 1e18;
    }

    cout << ans;
}
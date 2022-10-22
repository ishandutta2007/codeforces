#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x, y, l, r, Max;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> l >> r;

    int a = 1;

    while(a <= r)
    {
        int b = 1;
        while(b <= r)
        {
            if(a + b >= l && a + b <= r)
                v.push_back(a + b);

            if(b <= r / y)
                b *= y;
            else b = r + 1;
        }

        if(a <= r / x)
            a *= x;
        else a = r + 1;
    }

    v.push_back(l - 1);
    v.push_back(r + 1);
    sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++)
        Max = max(Max, v[i] - v[i - 1] - 1);

    cout << Max;
}
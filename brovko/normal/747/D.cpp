#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[200005];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0;

    while(x < n && a[x] >= 0)
        x++;

    if(x == n)
    {
        cout << 0;
        return 0;
    }

    while(x < n)
        {
            int p = 0;

            while(x < n && a[x] >= 0)
            {
                x++;
                p++;
            }

            if(p > 0)
                v.push_back(p);

            while(x < n && a[x] < 0)
                {
                    x++;
                    k--;
                }
        }

    /*cout << k << "\n";
    for(auto to:v)
        cout << to << ' ';
    cout << "\n";*/
    
    if(k < 0)
    {
        cout << -1;
        return 0;
    }

    if(a[n - 1] < 0)
        v.push_back(0);

    sort(v.begin(), v.end() - 1);

    int ans = 1e9;

    int y = v.size() * 2;
    int z = k;

    for(int i = 0; i < (int)v.size() - 1; i++)
    {
        if(z >= v[i])
        {
            z -= v[i];
            y -= 2;
        }
    }

    ans = min(ans, y);

    z = k - v[(int)v.size() - 1];
    y = v.size() * 2 - 1;

    for(int i = 0; i < (int)v.size() - 1; i++)
    {
        if(z >= v[i])
        {
            z -= v[i];
            y -= 2;
        }
    }
    if(z >= 0)
        ans = min(ans, y);

    cout << ans;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int n, a[100005], b[100005];
vector <pair <int, int> > v;

int f(int x)
{
    vector <pair <int, int> > u = v;

    int l = 0, r = n - 1;
    int ans = x, p = 0, fl = 0;

    while(r >= l)
    {
        if(p < u[l].x)
        {
            if(p + u[r].y >= u[l].x)
            {
                u[r] = {u[r].x, u[r].y - u[l].x + p};
                ans += 2 * (u[l].x - p);
                p = u[l].x;
            }
            else
            {
                ans += 2 * u[r].y;
                p += u[r].y;
                r--;
            }
        }
        else
        {
            ans += u[l].y;
            p += u[l].y;

            if(fl == 0)
                p += x;

            fl = 1;

            l++;
        }
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        v.pb({b[i], a[i]});
    }

    sort(v.begin(), v.end());

    cout << f(0);
}
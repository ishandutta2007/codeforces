#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> v, u;

    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
        {
            v.pb(i);

            if(i * i != n)
                u.pb(n / i);
        }

    int x = 0;

    for(int i = 0; i < v.size(); i++)
    {
        x++;

        if(x == k)
        {
            cout << v[i];
            return 0;
        }
    }

    reverse(u.begin(), u.end());

    for(int i = 0; i < u.size(); i++)
    {
        x++;

        if(x == k)
        {
            cout << u[i];
            return 0;
        }
    }

    cout << -1;
}
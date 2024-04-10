#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a[2][n], b[2][n];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> b[i][j];

    int k = 0;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            k += a[i][j] - b[i][j];

    if(k)
    {
        cout << "-1";
        return 0;
    }

    vector <int> a0, a1, b0, b1;
    li ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[0][i])
            a0.pb(i);

        if(a[1][i])
            a1.pb(i);

        if(b[0][i])
            b0.pb(i);

        if(b[1][i])
            b1.pb(i);

        while(!a0.empty() && !b0.empty())
        {
            ans += abs(a0.back() - b0.back());
            a0.pop_back();
            b0.pop_back();
        }

        while(!a1.empty() && !b1.empty())
        {
            ans += abs(a1.back() - b1.back());
            a1.pop_back();
            b1.pop_back();
        }

        while(!a0.empty() && !b1.empty())
        {
            ans += abs(a0.back() - b1.back()) + 1;
            a0.pop_back();
            b1.pop_back();
        }

        while(!a1.empty() && !b0.empty())
        {
            ans += abs(a1.back() - b0.back()) + 1;
            a1.pop_back();
            b0.pop_back();
        }
    }

    cout << ans;
}
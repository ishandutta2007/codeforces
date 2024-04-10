#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], dp[605][605], t[605][605];

int sum(int x, int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans |= t[x][r];

    return ans;
}

void inc(int x, int i)
{
    for(; i < 512; i = (i | i + 1))
        t[x][i] = 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    inc(0, 0);

    for(int i = 0; i < n; i++)
    {
        inc(a[i], a[i]);

        for(int x = 0; x < 512; x++)
        {
            if(sum(x ^ a[i], a[i] - 1))
                inc(x, a[i]);
        }
    }

    vector <int> v;

    for(int x = 0; x < 512; x++)
        if(sum(x, 511))
            v.pb(x);

    cout << v.size() << "\n";

    for(auto x:v)
        cout << x << ' ';
}
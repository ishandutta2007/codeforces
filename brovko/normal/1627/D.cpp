#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[1000005], used[1000005], b[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[a[i]]++;

    for(int i = 1; i < 1000005; i++)
    {
        int g = 0;

        for(int j = i; j < 1000005; j += i)
            if(b[j] && g != i)
                g = __gcd(g, j);

        if(g == i)
            used[i] = 1;
    }

    int ans = -n;

    for(int i = 0; i < 1000005; i++)
        ans += used[i];

    cout << ans;
}
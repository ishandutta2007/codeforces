#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int Min = 1e18, ans = 0;

    for(int i = 0; i < k; i++)
    {
        int s = 0;

        for(int j = i; j < n; j += k)
            s += a[j];

        if(s < Min)
        {
            Min = s;
            ans = i + 1;
        }
    }

    cout << ans;
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int Min = 1e9;

    for(int i=0; i<n; i++)
        Min=min(Min, a[i]);

    int x = -1e9;
    int ans = 1e9;

    for(int i=0; i<n; i++)
    {
        if(a[i] == Min)
        {
            ans = min(ans, i-x);
            x = i;
        }
    }

    cout << ans;
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    int ans=0;
    for(int i=0;i<n/2;i++)
        ans+=(a[i]+a[n-1-i])*(a[i]+a[n-1-i]);
    cout << ans;
}
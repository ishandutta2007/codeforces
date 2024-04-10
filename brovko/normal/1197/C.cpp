#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[300005], k, b[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
        b[i-1]=a[i]-a[i-1];
    sort(b, b+n-1);

    int ans=0;
    for(int i=0;i<n-k;i++)
        ans+=b[i];
    cout << ans;
}
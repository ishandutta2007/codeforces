#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i] > b[i])
            swap(a[i], b[i]);
    }

    int ans=0;

    for(int i=1; i<=n; i++)
    {
        ans+=max(0ll, a[i]-b[i-1]+1);
        if(i<n && a[i]==b[i])
            ans--;
    }
    cout << ans;
}
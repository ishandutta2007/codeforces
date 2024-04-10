#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    a[0]=0;
    a[n+1]=1001;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    n+=2;

    int ans=0;

    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        if(i-j==a[i]-a[j])
        ans=max(ans, j-i-1);
    cout << ans;
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[100005];

int f(int x)
{
    return (x-1)/k+1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
        cin >> a[i];

    int d=0;
    int ans=0;

    for(int i=0;i<m;i++)
    {
        if(i==m-1 || f(a[i]-d)!=f(a[i+1]-d))
        {
            ans++;
            d=i+1;
        }
    }

    cout << ans;
}
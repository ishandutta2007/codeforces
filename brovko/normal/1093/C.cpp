#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n/2;i++)
        cin >> a[n-1-i];

    for(int i=1;i<n/2;i++)
    {
        int x=max(a[i-1], a[n-1-i]-a[n-i]);
        a[i]=x;
        a[n-1-i]-=x;
    }

    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
}
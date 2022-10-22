#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], k;

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
    sort(a, a+n);
    a[n]=1e18;
    int x=n/2;
    while(k>=x-n/2+1)
    {
        int c=min(a[x+1]-a[x], k/(x-n/2+1));
        a[x]+=c;
        k-=c*(x-n/2+1);
        x++;
    }
    cout << a[x-1];
}
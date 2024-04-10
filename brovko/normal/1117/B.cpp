#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], k, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    int x=m/(k+1);
    cout << x*a[n-2]+(m-x)*a[n-1];
}
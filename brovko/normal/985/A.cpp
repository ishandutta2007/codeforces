#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdifpghig

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n/2;i++)
        cin >> a[i];

    int x=0, y=0;

    sort(a, a+n/2);
    for(int i=0;i<n/2;i++)
    {
        x+=abs(a[i]-(2*i+1));
        y+=abs(a[i]-(2*i+2));
    }
    cout << min(x, y);
}
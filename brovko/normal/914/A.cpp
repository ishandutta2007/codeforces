#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    int Max=-1e9;

    for(int i=0; i<n; i++)
        {
            if(a[i]<0 || round(sqrt(a[i]))*round(sqrt(a[i]))!=a[i])
                Max=a[i];
        }
    cout << Max;
}
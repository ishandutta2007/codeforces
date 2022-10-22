#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105], kp, ko;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
        if(a[i]>0)
            kp++;
        else if(a[i]<0)
            ko++;

    if(kp>=(n+1)/2)
        cout << 1;
    else if(ko>=(n+1)/2)
        cout << -1;
    else cout << 0;
}
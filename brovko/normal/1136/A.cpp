#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l[105], r[105], k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> l[i] >> r[i];
    cin >> k;
    for(int i=0;i<n;i++)
        if(k>=l[i] && k<=r[i])
    {
        cout << n-i;
        return 0;
    }
}
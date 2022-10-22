#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a[4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    for(int i=0;i<4;i++)
        cin >> a[i];
    sort(a, a+4);
    if(a[1]+a[2]==a[0]+a[3] || a[0]+a[1]+a[2]==a[3])
        cout << "YES";
    else cout << "NO";
}
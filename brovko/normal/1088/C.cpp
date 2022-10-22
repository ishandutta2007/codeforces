#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int INF=500000;

int n, a[2005], s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << n+1 << "\n";

    for(int i=0;i<n-1;i++)
    {
        cout << 1 << ' ' << i+1 << ' ' << INF+a[i+1]-1-a[i] << "\n";
        s+=a[i+1]-1-a[i];
    }
    cout << 1 << ' ' << n << ' ' << INF-s << "\n";
    cout << 2 << ' ' << n << ' ' << INF;
}
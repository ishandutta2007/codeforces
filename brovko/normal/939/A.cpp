#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        if(a[a[a[i]]] == i)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
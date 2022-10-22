#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int x, a[3];

        cin >> x;

        for(int i = 0; i < 3; i++)
            cin >> a[i];

        if(a[x - 1] == 0 || a[0] == 1 || a[1] == 2 || a[2] == 3)
            cout << "NO\n";
        else cout << "YES\n";
    }
}
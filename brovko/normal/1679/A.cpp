#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        li n;
        cin >> n;

        if(n == 2 || n % 2)
            cout << "-1\n";

        else cout << n / 6 + (bool)(n % 6) << ' ' << n / 4 << "\n";
    }
}
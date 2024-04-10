#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
        {
            cin >> a >> b;
            if(a%b)
                cout << "NO" << endl;
            else cout << "YES" << endl;
        }
}
#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                cout << 9;
            else cout << (i + 7) % 10;
        }

        cout << "\n";
    }
}
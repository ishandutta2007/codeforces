#include <bits/stdc++.h>
//#define int long long
#define ld long double
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
        int n, r, b;
        cin >> n >> r >> b;

        b++;

        while(b > 0)
        {
            for(int j = 0; j < r / b; j++)
                cout << 'R';

            r -= r / b;
            b--;

            if(b > 0)
                cout << 'B';
        }

        cout << "\n";
    }
}
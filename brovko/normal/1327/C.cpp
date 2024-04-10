#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    cout << n + m + n * m - 3 << "\n";

    for(int i = 0; i < n - 1; i++)
        cout << "U";

    for(int i = 0; i < m - 1; i++)
        cout << "L";

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < m - 1; j++)
                cout << "R";
        }
        else
        {
            for(int j = 0; j < m - 1; j++)
                cout << "L";
        }

        if(i < n - 1)
            cout << "D";
    }
}
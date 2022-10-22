#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
                cout << '(';

            for(int j = 0; j < i; j++)
                cout << ')';

            for(int j = 0; j < n - i; j++)
                cout << "()";

            cout << "\n";
        }
    }
}
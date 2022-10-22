#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int k = 2 * min(i + 1, n - i) - 1;

        for(int j = 0; j < (n - k) / 2; j++)
            cout << "*";

        for(int j = 0; j < k; j++)
            cout << 'D';

        for(int j = 0; j < (n - k) / 2; j++)
            cout << "*";

        cout << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            cout << "P";

            if(i == 0)
                cout << "RL";
            else cout << "LR";
        }

        if(i < n - 1)
            cout << "R";
    }
}
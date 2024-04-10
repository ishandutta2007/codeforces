#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[100005];
char c;

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
            cin >> c;
            a[i] = c - '0';
        }

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] + 1 == x)
                x = a[i];
            else x = a[i] + 1;

            cout << x - a[i];
        }

        cout << "\n";
    }
}
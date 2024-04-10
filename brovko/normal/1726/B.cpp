#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        if(n % 2 == 0 && m % 2 || n > m)
        {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        if(n % 2)
        {
            for(int i = 0; i < n - 1; i++)
                cout << "1 ";

            cout << m - n + 1 << "\n";
        }
        else
        {
            for(int i = 0; i < n - 2; i++)
                cout << "1 ";

            cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << "\n";
        }
    }
}
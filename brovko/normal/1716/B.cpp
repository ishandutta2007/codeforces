#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

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
        int n;
        cin >> n;

        cout << n << "\n";

        vector <int> p(n);

        for(int i = 0; i < n; i++)
            p[i] = i + 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << p[j] << ' ';

            cout << "\n";

            swap(p[n - 1], p[i]);
        }
    }
}
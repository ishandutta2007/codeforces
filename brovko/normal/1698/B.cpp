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
        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(k == 1)
            cout << (n - 1) / 2 << "\n";
        else
        {
            int k = 0;

            for(int i = 1; i < n - 1; i++)
                k += (a[i] > a[i - 1] + a[i + 1]);

            cout << k << "\n";
        }
    }
}
#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = n;
        bool F = 1;

        vector <int> k(n + 1);

        while(x >= 0 && F)
        {
            x--;

            if(x < 0)
                break;

            k[a[x]]++;

            if(k[a[x]] == 2)
                F = 0;
        }

        cout << x + 1 << "\n";
    }
}
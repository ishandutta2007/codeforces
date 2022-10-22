#include <bits/stdc++.h>
#define int long long
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
        int n, m, k;
        cin >> n >> m >> k;

        vector <int> a(k);

        for(int i = 0; i < k; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int c1 = 0, c2 = 0;

        for(int i = 0; i < k; i++)
        {
            int x = a[i] / n;

            if(x >= 2)
                c1 += x;
        }

        if(m % 2 && a[k - 1] / n == 2)
            c1 = 0;

        for(int i = 0; i < k; i++)
        {
            int x = a[i] / m;

            if(x >= 2)
                c2 += x;
        }

        if(n % 2 && a[k - 1] / m == 2)
            c2 = 0;

        if(c1 >= m || c2 >= n)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
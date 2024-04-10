#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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
        int n, m;
        cin >> n >> m;

        vector <int> a(m);

        for(int i = 0; i < m; i++)
            cin >> a[i];

        vector <int> k(n + 1);

        for(int i = 0; i < m; i++)
            k[a[i]]++;

        int L = 0, R = 1e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;
            li k2 = 0, s = 0, w = 0;

            for(int i = 1; i <= n; i++)
            {
                k2 += max(0, k[i] - M);
                s += k[i];
                w += max(0, (M - k[i]) / 2);
            }

            if(w >= k2)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}
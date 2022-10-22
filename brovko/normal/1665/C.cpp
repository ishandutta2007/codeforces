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
        int n;
        cin >> n;

        vector <int> p(n);

        for(int i = 0; i < n - 1; i++)
            cin >> p[i];

        vector <int> k(n + 1);

        for(int i = 0; i < n - 1; i++)
            k[p[i]]++;

        k[0] = 1;

        sort(k.rbegin(), k.rend());

        int L = 0, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;
            li T = 0;

            for(int i = 0; i <= n; i++)
            {
                if(k[i] > 0)
                {
                    T++;
                    T += max(0, k[i] - M + i);
                }
            }

            if(T <= M)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}
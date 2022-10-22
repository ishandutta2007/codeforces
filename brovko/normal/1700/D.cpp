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

//    int t;
//    cin >> t;

//    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <li> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        li Max = 0;
        vector <li> ans(n + 1);

        for(int i = 1; i <= n; i++)
        {
            Max = max(Max, (ps[i] + i - 1) / i);
            ans[i] = max(Max, (ps[n] + i - 1) / i);
        }

        int q;
        cin >> q;

        while(q--)
        {
            int x;
            cin >> x;

            int L = 0, R = n + 1;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(ans[M] <= x)
                    R = M;
                else L = M;
            }

            cout << (R == n + 1 ? -1 : R) << "\n";
        }
    }
}
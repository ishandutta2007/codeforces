#include <bits/stdc++.h>
//#define int long long
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

        int L = 0, R = 1e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;
            int k = M / 3;

            li b = (3 * k) * 1ll * k;

            li r = 0;

            if(M % 3 > 0)
                r += 2 * k;

            if(M % 3 > 1)
                r += 2 * k + 1;

            if(2 * (b + r) >= n)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}
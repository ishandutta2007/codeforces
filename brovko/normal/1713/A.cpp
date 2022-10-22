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

        vector <int> x(n), y(n);

        int mnx = 0, mxx = 0, mny = 0, mxy = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];

            mnx = min(mnx, x[i]);
            mxx = max(mxx, x[i]);
            mny = min(mny, y[i]);
            mxy = max(mxy, y[i]);
        }

        cout << (mxx - mnx + mxy - mny) * 2 << "\n";
    }
}
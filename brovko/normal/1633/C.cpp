#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
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
        int hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;

        bool F = 0;

        for(int i = 0; i <= k; i++)
        {
            if((hc + i * a + dm - 1) / dm >= (hm + dc + (k - i) * w - 1) / (dc + (k - i) * w))
                F = 1;
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}
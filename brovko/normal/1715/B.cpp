#include <bits/stdc++.h>
#define int long long
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
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        vector <int> a(n);

        a[0] = b * k;
        s -= b * k;

        if(s < 0 || s > n * (k - 1))
        {
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            int x = min(k - 1, s);
            s -= x;
            a[i] += x;
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}
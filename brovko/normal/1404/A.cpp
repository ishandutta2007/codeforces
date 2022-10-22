#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, k, a[300005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> s;

        for(int i = 0; i < n; i++)
            a[i] = -1;

        int f = 1;

        int k0 = 0, k1 = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(a[i % k] == 1)
                    f = 0;

                if(a[i % k] == -1)
                {
                    a[i % k] = 0;
                    k0++;
                }
            }

            if(s[i] == '1')
            {
                if(a[i % k] == 0)
                    f = 0;

                if(a[i % k] == -1)
                {
                    a[i % k] = 1;
                    k1++;
                }
            }
        }

        if(f == 1 && k0 * 2 <= k && k1 * 2 <= k)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
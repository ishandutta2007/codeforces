#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[1005], used[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            used[i] = 0;

        int g = 0;

        a[n] = 1;

        for(int i = 0; i < n; i++)
        {
            int Max = n;

            for(int j = 0; j < n; j++)
                if(used[j] == 0 && __gcd(g, a[j]) >= __gcd(g, a[Max]))
                    Max = j;

            used[Max] = 1;
            g = __gcd(g, a[Max]);
            cout << a[Max] << ' ';
        }

        cout << "\n";
    }
}
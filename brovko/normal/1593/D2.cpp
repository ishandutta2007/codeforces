#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
mt19937 rnd(time(NULL));
const int N = 100;

int t, n, a[45];

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

        int ans = 1;

        for(int i = 0; i < N; i++)
        {
            int x = rnd() % n, y = x;

            while(y == x)
                y = rnd() % n;

            int z = abs(a[x] - a[y]);

            vector <int> v;

            for(int j = 1; j * j <= z; j++)
            {
                if(z % j == 0)
                {
                    v.pb(j);

                    if(j * j != z)
                        v.pb(z / j);
                }
            }

            for(auto d:v)
            {
                int k = 0;

                for(int j = 0; j < n; j++)
                    if((a[j] - a[x]) % d == 0)
                        k++;

                if(k * 2 >= n)
                    ans = max(ans, d);
            }
        }

        map <int, int> m;

        int F = 0;

        for(int i = 0; i < n; i++)
        {
            m[a[i]]++;

            if(m[a[i]] * 2 >= n && F == 0)
            {
                F = 1;
                cout << "-1\n";
            }
        }

        if(F == 0)
            cout << ans << "\n";
    }
}
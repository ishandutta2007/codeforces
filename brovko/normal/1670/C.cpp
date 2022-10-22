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

        vector <int> a(n), b(n), c(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
            cin >> c[i];

        for(int i = 0; i < n; i++)
        {
            a[i]--;
            b[i]--;
            c[i]--;
        }

        vector <int> ab(n);

        for(int i = 0; i < n; i++)
            ab[a[i]] = b[i];

        vector <int> C(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(C[i] == -1)
            {
                C[i] = i;

                int x = ab[i];

                while(C[x] == -1)
                {
                    C[x] = i;
                    x = ab[x];
                }
            }
        }

        vector <int> used(n);

        for(int i = 0; i < n; i++)
            if(ab[i] == i)
                used[i] = 1;

        for(int i = 0; i < n; i++)
            if(c[i] != -1)
                used[C[c[i]]] = 1;

        int ans = 0;

        for(int i = 0; i < n; i++)
            if(C[i] == i && used[i] == 0)
                ans++;

        int p = 1, MOD = 1e9 + 7;

        while(ans--)
            p = p * 2 % MOD;

        cout << p << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        vector <int> ca(n), cb(n);

        for(int i = 0; i < n; i++)
        {
            cin >> ca[i];
            ca[i]--;
        }

        for(int i = 0; i < n; i++)
        {
            cin >> cb[i];
            cb[i]--;
        }

        vector <int> r(n);

        for(int i = 0; i < n; i++)
            r[ca[i]] = i;

        vector <int> used(n);

        int L = 0, R = n - 1, ans = 0;

        for(int i = 0; i < n; i++)
            if(used[ca[i]] == 0)
            {
                int sz = 0;
                int x = ca[i];

                while(used[x] == 0)
                {
                    sz++;
                    used[x] = 1;
                    x = cb[r[x]];
                }

//                cout << "! " << sz << endl;

                for(; sz >= 2; sz -= 2)
                {
                    ans += R - L;
                    L++;
                    R--;
                }
            }

        cout << ans * 2 << "\n";
    }
}
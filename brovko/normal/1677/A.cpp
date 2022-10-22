#include <bits/stdc++.h>
//#define int long long
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

        vector <int> p(n);

        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }

        int pref[n][n], suf[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == 0)
                    pref[i][j] = (p[i] <= j);
                else pref[i][j] = pref[i - 1][j] + (p[i] <= j);
            }

        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < n; j++)
            {
                if(i == n - 1)
                    suf[i][j] = (p[i] <= j);
                else suf[i][j] = suf[i + 1][j] + (p[i] <= j);
            }

        li ans = 0;

        for(int i = 1; i < n; i++)
            for(int j = i + 1; j < n - 1; j++)
            {
                ans += pref[i - 1][p[j]] * suf[j + 1][p[i]];
//                cout << i + 1 << ' ' << j + 1 << ' ' << pref[i - 1][p[j]] * suf[j + 1][p[i]] << endl;
//
//                if(i == 2 && j == 4)
//                    cout << "! " << pref[i - 1][p[j]] << ' ' << suf[j + 1][p[i]] << endl;
            }

        cout << ans << "\n";
    }
}
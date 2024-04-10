#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <int> c(26);

        for(int i = 0; i < n; i++)
            c[s[i] - 'a']++;

        string ans;

        for(int i = 0; i < k; i++)
        {
            int mex = 0;

            while(c[mex])
                mex++;

            mex = min(mex, n / k);

            for(int j = 0; j < mex; j++)
                c[j]--;

            ans += 'a' + mex;
        }

        cout << ans << "\n";
    }
}
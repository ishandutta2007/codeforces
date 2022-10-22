#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;

        vector <int> v;

        int k = 0;

        for(auto to:s)
        {
            if(to == '1')
                k++;
            else
            {
                v.push_back(k);
                k = 0;
            }
        }

        v.push_back(k);

        sort(v.begin(), v.end());
        int ans = 0;

        for(int i = (int)v.size() - 1; i >= 0; i -= 2)
            ans += v[i];

        cout << ans << "\n";
    }
}
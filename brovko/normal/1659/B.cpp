#include <bits/stdc++.h>
//#define int long long
#define ld long double
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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <int> ans(n);

        for(int i = 0; i < n; i++)
            if(k % 2)
                s[i] = '0' + '1' - s[i];

        for(int i = 0; i < n; i++)
            if(s[i] == '0' && k > 0)
            {
                k--;
                s[i] = '1';
                ans[i]++;
            }

        if(k)
        {
            ans[n - 1] += k;

            if(k % 2)
                s[n - 1] = '0';
        }

        cout << s << "\n";

        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';

        cout << "\n";
    }
}
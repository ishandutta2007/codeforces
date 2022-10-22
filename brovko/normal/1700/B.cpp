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
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(s[0] == '9')
        {
            vector <int> ans(n + 1);
            reverse(s.begin(), s.end());

            for(int i = 0; i < n; i++)
            {
                int c = ans[i] + 1 - (s[i] - '0');

                if(c < 0)
                {
                    c += 10;
                    ans[i + 1]--;
                }

                ans[i] = c;
            }

            for(int i = n - 1; i >= 0; i--)
                cout << ans[i];

            cout << "\n";
        }
        else
        {
            for(int i = 0; i < s.size(); i++)
                cout << 9 - (s[i] - '0');

            cout << "\n";
        }
    }
}
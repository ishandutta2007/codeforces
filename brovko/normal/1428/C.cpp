#include <bits/stdc++.h>
#define int long long
#define ld long double

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
        int n = s.size();

        int c = 0, ans = 0, kb = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'A')
                c--;
            else
            {
                c++;
                kb++;
            }

            ans = max(ans, c);
        }

        cout << n - 2 * kb + ans + ans % 2 << "\n";
    }
}
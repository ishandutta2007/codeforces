#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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

        int Min = 0;
        int ans = 0;
        int cur = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '+')
                cur++;
            else cur--;

            if(cur < Min)
            {
                cur = Min;
                ans += i + 1;
            }
        }

        ans += n;

        cout << ans << "\n";
    }
}
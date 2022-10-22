#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        int l1 = 1e9;
        int r0 = -1e9;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                r0 = i;
            else l1 = min(l1, i);
        }

        if(r0 < l1)
            cout << s << "\n";
        else
        {
            for(int i = 0; i < l1; i++)
                cout << s[i];

            for(int i = r0; i < n; i++)
                cout << s[i];

            cout << "\n";
        }
    }
}
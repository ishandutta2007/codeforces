#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

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
        cin >> s;
        n = s.size();

        int ans = 0, r = -1, c0 = 0, c1 = 0, nc0 = 0, nc1 = 0;

        for(int l = 0; l < n; l++)
        {
            while(r < n - 1 && (c0 + nc1 == 0 || nc0 + c1 == 0))
            {
                r++;

                if(s[r] == '0' && r % 2 == 0)
                    c0++;

                if(s[r] == '0' && r % 2 != 0)
                    nc0++;

                if(s[r] == '1' && r % 2 == 0)
                    c1++;

                if(s[r] == '1' && r % 2 != 0)
                    nc1++;
            }

            if(c0 + nc1 > 0 && nc0 + c1 > 0)
            {
                if(s[r] == '0' && r % 2 == 0)
                    c0--;

                if(s[r] == '0' && r % 2 != 0)
                    nc0--;

                if(s[r] == '1' && r % 2 == 0)
                    c1--;

                if(s[r] == '1' && r % 2 != 0)
                    nc1--;

                r--;
            }

            ans += r - l + 1;

            if(s[l] == '0' && l % 2 == 0)
                c0--;

            if(s[l] == '0' && l % 2 != 0)
                nc0--;

            if(s[l] == '1' && l % 2 == 0)
                c1--;

            if(s[l] == '1' && l % 2 != 0)
                nc1--;
        }

        cout << ans << "\n";
    }
}
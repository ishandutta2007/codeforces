#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, q, l, r, ps[300005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> q >> s;

        ps[0] = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '+' && i % 2 == 0 || s[i] == '-' && i % 2 != 0)
                ps[i + 1] = ps[i] + 1;

            else ps[i + 1] = ps[i] - 1;
        }

        while(q--)
        {
            cin >> l >> r;

            if(ps[r] - ps[l - 1] == 0)
                cout << "0\n";

            else if((r - l) % 2 == 0)
                cout << "1\n";

            else cout << "2\n";
        }
    }
}
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, q;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> q;
        cin >> s;

        int l0 = 1e9, r0 = -1e9, l1 = 1e9, r1 = -1e9;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                l0 = min(l0, i);
                r0 = max(r0, i);
            }
            else
            {
                l1 = min(l1, i);
                r1 = max(r1, i);
            }
        }

        while(q--)
        {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            if(s[x] == '0' && x != l0 || s[x] == '1' && x != l1 || s[y] == '0' && y != r0 || s[y] == '1' && y != r1)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
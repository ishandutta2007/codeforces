#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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
        int n, c, q;
        cin >> n >> c >> q;

        string s;
        cin >> s;

        li len = s.size();

        vector <li> l(c), r(c), L(c), R(c);

        for(int i = 0; i < c; i++)
        {
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;

            L[i] = len;
            R[i] = r[i] + (L[i] - l[i]);

            len = R[i] + 1;
        }

        while(q--)
        {
            li x;
            cin >> x;

            x--;

            for(int i = c - 1; i >= 0; i--)
            {
                if(x >= L[i] && x <= R[i])
                    x -= L[i] - l[i];
            }

            cout << s[x] << "\n";
        }
    }
}
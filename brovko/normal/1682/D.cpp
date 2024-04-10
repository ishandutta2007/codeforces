#include <bits/stdc++.h>
//#define int long long
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

        int k = 0;

        for(int i = 0; i < n; i++)
            if(s[i] == '1')
                k++;

        if(k % 2 || k == 0)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int x = -1, y = -1;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                y = i;

                if(x == -1)
                    x = i;
            }
        }

        int p = (y - 1 + n) % n;

        while(s[p] == '0' && s[(p - 1 + n) % n] == '0')
            p = (p - 1 + n) % n;

        if(s[p] == '0')
        {
            for(int i = 0; i < n; i++)
            {
                if(i == x)
                    continue;

                else if(i >= p || i <= x)
                {
                    if(i > y || i < x)
                        cout << i + 1 << ' ' << (i + 1) % n + 1 << "\n";

                    else if(i == p)
                        cout << i + 1 << ' ' << (y + 1) % n + 1 << "\n";

                    else cout << i + 1 << ' ' << (i - 1 + n) % n + 1 << "\n";
                }

                else if(s[(i - 1 + n) % n] == '1')
                    cout << i + 1 << ' ' << x + 1 << "\n";

                else cout << i + 1 << ' ' << (i - 1 + n) % n + 1 << "\n";
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(i == x)
                    continue;

                else if(i >= y || i <= x)
                {
                    cout << i + 1 << ' ' << (i + 1) % n + 1 << "\n";
                }

                else if(s[(i - 1 + n) % n] == '1')
                    cout << i + 1 << ' ' << x + 1 << "\n";

                else cout << i + 1 << ' ' << (i - 1 + n) % n + 1 << "\n";
            }
        }
    }
}
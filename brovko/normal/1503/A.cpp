#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

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
        string a, b;

        int x = 0, y = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(x > y)
                {
                    a += ")";
                    b += "(";
                    x--;
                    y++;
                }
                else
                {
                    a += "(";
                    b += ")";
                    x++;
                    y--;
                }
            }
            else
            {
                if(max(x, y) >= 2 && min(x, y) >= 1 || i == n - 1)
                {
                    a += ")";
                    b += ")";
                    x--;
                    y--;
                }
                else
                {
                    a += "(";
                    b += "(";
                    x++;
                    y++;
                }
            }
        }

        if(s[0] == '0' || x != 0 || y != 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n" << a << "\n" << b << "\n";
        }
    }
}
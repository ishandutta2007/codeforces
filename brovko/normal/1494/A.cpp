#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t;
string s, x;

int f()
{
    int k = 0;

    for(auto to:x)
    {
        if(to == '(')
            k++;
        else k--;

        if(k < 0)
            return 0;
    }

    if(k == 0)
        return 1;

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;

        int fl = 0;

        for(int i = 0; i < 8; i++)
        {
            x = "";

            for(auto to:s)
            {
                if(to == 'A' && (i & 1) > 0 || to == 'B' && (i & 2) > 0 || to == 'C' && (i & 4) > 0)
                    x += "(";
                else x += ")";
            }

            if(f())
                fl = 1;
        }

        if(fl)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
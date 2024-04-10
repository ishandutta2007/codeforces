#include <bits/stdc++.h>
//#define int long long
#define ld lond double
#define y1 eohfweoifhew

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

        string x;
        string y = "abacaba";

        int F = 0;

        for(int i = 0; i < n - 6; i++)
            if(F == 0)
        {
            int f = 0;
            x = s;

            for(int j = i; j < i + 7; j++)
            {
                if(x[j] != '?' && x[j] != y[j - i])
                    f = 1;

                x[j] = y[j - i];
            }

            for(int j = 0; j < n - 6; j++)
                if(j != i && x.substr(j, 7) == y)
                    f = 1;

            if(f == 0 && F == 0)
                {
                    F = 1;
                    cout << "Yes\n";

                    for(int j = 0; j < n; j++)
                        if(x[j] == '?')
                            cout << 'd';
                        else cout << x[j];

                    cout << "\n";
                }
        }

        if(F == 0)
            cout << "No\n";
    }
}
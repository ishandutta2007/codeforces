#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t;
string a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        int Max = 0;

        for(int la = 0; la < a.size(); la++)
            for(int ra = la + 1; ra <= a.size(); ra++)
                for(int lb = 0; lb <= (int)b.size() - ra + la; lb++)
                {
                    if(a.substr(la, ra - la) == b.substr(lb, ra - la))
                        Max = max(Max, ra - la);
                }

        cout << a.size() + b.size() - 2 * Max << "\n";
    }
}
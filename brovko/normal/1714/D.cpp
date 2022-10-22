#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int n;
        cin >> n;

        vector <string> x(n);

        for(int i = 0; i < n; i++)
            cin >> x[i];

        int r = 0;

        vector <pair <int, int> > v;

        while(r < s.size())
        {
            int Max = r;
            int X = 0, Y = 0;

            for(int i = 0; i < n; i++)
                for(int j = 0; j <= min(r, (int)s.size() - (int)x[i].size()); j++)
                {
                    if(s.substr(j, x[i].size()) == x[i] && j + x[i].size() >= Max)
                    {
                        Max = j + x[i].size();
                        X = i + 1;
                        Y = j + 1;
                    }
                }

            if(Max > r)
            {
                r = Max;
                v.pb({X, Y});
            }
            else
            {
                cout << "-1\n";
                break;
            }
        }

        if(r >= s.size())
        {
            cout << v.size() << "\n";

            for(auto x:v)
                cout << x.f << ' ' << x.s << "\n";
        }
    }
}
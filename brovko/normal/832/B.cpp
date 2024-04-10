#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, g[128];
string s, t, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    for(auto to:s)
        g[to] = 1;

    cin >> n;
    while(n--)
    {
        cin >> x;

        if(x.size() + 1 < t.size())
            cout << "NO\n";
        else
        {
            int y = -1;
            for(int i = 0; i < t.size(); i++)
                if(t[i] == '*')
                    y = i;

            if(y == -1)
            {
                int R = 0;
                int f = 1;

                for(int i = 0; i < t.size(); i++)
                {
                    if(t[i] == '?')
                    {
                        if(R < x.size() && g[x[R]] == 1)
                            R++;
                        else f = 0;
                    }
                    else
                    {
                        if(R < x.size() && x[R] == t[i])
                            R++;
                        else f = 0;
                    }
                }

                if(f == 1 && R == x.size())
                    cout << "YES\n";
                else cout << "NO\n";
            }
            else
            {
                int L = 0;
                int f = 1;

                for(int i = 0; i < y; i++)
                {
                    if(t[i] == '?')
                    {
                        if(L < x.size() && g[x[L]] == 1)
                            L++;
                        else f = 0;
                    }
                    else
                    {
                        if(L < x.size() && x[L] == t[i])
                            L++;
                        else f = 0;
                    }
                }

                //cout << f << ' ' << L << "\n";

                int R = (int)x.size() - 1;

                int k = (int)t.size() - 1;

                for(int i = k; i > y; i--)
                {
                    if(t[i] == '?')
                    {
                        if(R < x.size() && g[x[R]] == 1)
                            R--;
                        else f = 0;
                    }
                    else
                    {
                        if(R < x.size() && x[R] == t[i])
                            R--;
                        else f = 0;
                    }
                }

                //cout << f << ' ' << R << "\n";

                for(int i = L; i <= R; i++)
                    if(g[x[i]])
                        f = 0;

                if(f)
                    cout << "YES\n";
                else cout << "NO\n";
            }
        }


    }
}

/*

abc
a?a?a*
1
abaca

*/
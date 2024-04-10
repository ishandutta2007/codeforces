#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    s += ";";

    string t;
    int F = 1;

    vector <string> a, b;


    for(auto x:s)
    {
        if(x == ';' || x == ',')
        {
            if(t.size() == 0 || t[0] == '0' && t.size() > 1 || F == 0)
                b.pb(t);
            else a.pb(t);

            F = 1;
            t = "";
        }
        else
        {
            t += x;

            if(x < '0' || x > '9')
                F = 0;
        }
    }

    if(a.size() == 0)
        cout << '-';
    else
    {
        cout << '"';

        for(int i = 0; i < a.size(); i++)
        {
            string x = a[i];
            cout << x;

            if(i + 1 < a.size())
                cout << ',';
        }

        cout << '"';
    }

    cout << "\n";

    if(b.size() == 0)
        cout << '-';
    else
    {
        cout << '"';

        for(int i = 0; i < b.size(); i++)
        {
            string x = b[i];
            cout << x;

            if(i + 1 < b.size())
                cout << ',';
        }

        cout << '"';
    }
}
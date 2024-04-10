#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int i = 0;

    while(s[i] != '+')
        i++;

    int a = i;

    while(s[i] != '=')
        i++;

    int b = i - a - 1;

    int c = (int)s.size() - a - b - 2;

    if(a + b == c)
    {
        cout << s;
        return 0;
    }

    if(a + b + 2 == c)
    {
        cout << "|" << s.substr(0, ((int)s.size() - 1));
        return 0;
    }

    if(a + b - 2 == c)
    {
        if(a > 1)
            a--;
        else b--;

        c++;

        for(int i = 0; i < a; i++)
            cout << '|';

        cout << '+';

        for(int i = 0; i < b; i++)
            cout << '|';

        cout << '=';

        for(int i = 0; i < c; i++)
            cout << '|';

        return 0;
    }

    cout << "Impossible";
}
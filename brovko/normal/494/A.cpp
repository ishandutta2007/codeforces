#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    int x = 0, k = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            x++;

        if(s[i] == ')')
            x--;

        if(s[i] == '#')
        {
            x--;
            k++;
        }

        if(x < 0)
        {
            cout << -1;
            return 0;
        }
    }

//    cout << k << endl;

    int y = 0, c = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            y++;

        if(s[i] == ')')
            y--;

        if(s[i] == '#')
        {
            y--;
            c++;

            if(c == k)
                y -= x;
        }

//        cout << y << ' ';

        if(y < 0)
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < k - 1; i++)
        cout << "1\n";

    cout << x + 1;
}
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;
int l1, r1, l2, r2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);

    int n = 0;

    for(auto to:s)
    {
        if(to >= '0' && to <= '9')
            n = n * 10 + to - '0';
    }

    l1 = 1;
    r1 = n;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == '+')
        {
            l1++;
            r1 += n;
        }

        if(s[i] == '-')
        {
            l2++;
            r2 += n;
        }
    }

    int x = -1;

    if(l1 - n >= l2 && l1 - n <= r2)
        x = l1 - n;

    if(r1 - n >= l2 && r1 - n <= r2)
        x = r1 - n;

    if(l2 + n >= l1 && l2 + n <= r1)
        x = l2;

    if(r2 + n >= l1 && r2 + n <= r1)
        x = r2;

    if(x == -1)
    {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible\n";

    s = "+ " + s;

    for(int i = 0; i < s.size(); i++)
    {
        int to = s[i];

        if(to == '+')
        {
            int y = min(x + n - l1, n - 1);
            l1 += y;

            if(i != 0)
                cout << "+ ";

            cout << y + 1 << ' ';
        }
        else

        if(to == '-')
        {
            int y = min(x - l2, n - 1);
            l2 += y;

            cout << "- " << y + 1 << ' ';
        }

        else if(s[i] >= '0' && s[i] <= '9')
            cout << s[i];

        else if(s[i] == '=')
            cout << "= ";
    }
}
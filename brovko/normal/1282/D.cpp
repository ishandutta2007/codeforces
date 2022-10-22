#include <bits/stdc++.h>
//#define int long long
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

    for(int i = 0; i < 300; i++)
        cout << 'a';

    cout << endl;

    int x;
    cin >> x;

    if(x == 0)
        return 0;

    for(int i = 0; i < 300; i++)
        cout << 'b';

    cout << endl;

    int y;
    cin >> y;

    if(y == 0)
        return 0;

    int n = 600 - x - y;
    x -= 300 - n;

    if(x == 0)
    {
        for(int i = 0; i < n; i++)
            cout << 'a';

        return 0;
    }

    string s;

    for(int i = 0; i < n; i++)
        s += 'a';

    for(int i = 0; i < n; i++)
    {
        s[i] = 'b';

        cout << s << endl;

        int z;
        cin >> z;

        if(z == 0)
            return 0;

        if(z < x)
            x = z;
        else s[i] = 'a';
    }
}
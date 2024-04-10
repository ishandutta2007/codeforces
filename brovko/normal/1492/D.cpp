#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int a, b, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k;

    if(k == 0)
    {
        cout << "Yes\n";

        for(int i = 0; i < b; i++)
            cout << 1;

        for(int i = 0; i < a; i++)
            cout << 0;

        cout << "\n";

        for(int i = 0; i < b; i++)
            cout << 1;

        for(int i = 0; i < a; i++)
            cout << 0;

        return 0;
    }

    b--;

    if(k >= a + b || b == 0 || a == 0)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    b--;

    int p = a + b + 1;

    string s = "1", t = "1";

    for(int i = 0; i < p; i++)
    {
        if(i == 0)
        {
            s += "1";
            t += "0";
        }
        else if(i == k)
        {
            s += "0";
            t += "1";
        }
        else if(b > 0)
        {
            s += "1";
            t += "1";
            b--;
        }
        else
        {
            s += "0";
            t += "0";
        }

//        cout << i << ' ' << s.size() << ' ' << t.size() << endl;
    }

    cout << s << "\n" << t;
}
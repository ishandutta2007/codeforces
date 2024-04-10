#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int q;
string s, t, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> s >> t;
        a = s;
        b = t;

        if(a.size() > b.size())
        {
            swap(a, b);
            swap(s, t);
        }

        while(a != b && b.substr(0, a.size()) == a)
        {
            a += s;

            if(a.size() > b.size())
            {
                swap(a, b);
                swap(s, t);
            }
        }

        if(a != b)
            cout << "-1\n";
        else cout << a << "\n";
    }
}
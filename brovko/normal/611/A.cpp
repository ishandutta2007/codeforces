#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int x;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> s >> s;

    if(s == "month")
    {
        if(x == 31)
            cout << 7;

        else if(x > 29)
            cout << 11;

        else cout << 12;
    }
    else
    {
        if(x == 5 || x == 6)
            cout << 53;

        else cout << 52;
    }
}
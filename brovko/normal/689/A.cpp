#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, x;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(auto to:s)
    {
        if(to == '0' || to == '7' || to == '9')
            x |= 1;

        if(to == '1' || to == '2' || to == '3')
            x |= 2;

        if(to == '1' || to == '4' || to == '7' || to == '0')
            x |= 4;

        if(to == '3' || to == '6' || to == '9' || to == '0')
            x |= 8;
    }

    if(x == 15)
        cout << "YES";
    else cout << "NO";
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, x, y;

int32_t main()
{
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        cin >> x >> y;
        if(x==2 && y==3)
            cout << "YES\n";
        else if(x>=y)
            cout << "YES\n";
        else if(x>=4)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
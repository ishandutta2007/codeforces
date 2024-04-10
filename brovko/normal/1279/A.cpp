#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, r, g, b;

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> r >> g >> b;
        int x=max(r, max(g, b));
        int s=r+g+b;
        if(x>s-x+1)
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll x,y;
        cin >> x >> y;
        if(x>y) cout << x+y << "\n";
        else if((y%x)==0) cout << y << "\n";
        else cout << y-(y%x)/2 << "\n";
    }
    return 0;
}
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
        ll res=0;
        for(ll k=1;k*(k+2)<=x;k++)
        {
            res+=max(0ll,min(y,(x/k)-1)-(k+1)+1);
        }
        cout << res << "\n";
    }
    return 0;
}
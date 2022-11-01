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
        int n;
        cin >> n;
        ll x=(1ll<<60),y=(1ll<<60);
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            if(i&1) x=min(x,n*a+i);
            else y=min(y,n*a+i);
        }
        if((n&1)||x>y) cout << "Mike\n";
        else cout << "Joe\n";
    }
    return 0;
}
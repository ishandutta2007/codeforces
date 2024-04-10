#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        ll a,b;
        cin >> a >> b;
        ll l=0,r=1000001;
        while(l<r-1)
        {
            ll m=(l+r)/2;
            if(m*m*m>=a*b) r=m;
            else l=m;
        }
        if(r*r*r==a*b&&(a%r)==0&&(b%r)==0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
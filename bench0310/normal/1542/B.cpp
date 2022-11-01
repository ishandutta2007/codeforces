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
        ll n,a,b;
        cin >> n >> a >> b;
        ll x=1;
        bool res=(((n-1)%b)==0);
        while(a>1&&x*a<=n)
        {
            x*=a;
            res|=(((n-x)%b)==0);
        }
        if(res) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
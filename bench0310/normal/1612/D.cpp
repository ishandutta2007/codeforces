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
        ll a,b,x;
        cin >> a >> b >> x;
        if(a<b) swap(a,b);
        bool ok=0;
        while(b!=0)
        {
            ll d=(a%b);
            ok|=(d<=x&&x<=a&&((a-x)%b)==0);
            tie(a,b)={b,d};
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
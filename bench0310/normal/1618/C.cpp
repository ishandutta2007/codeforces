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
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll d=0;
        for(int x=0;x<2;x++)
        {
            ll g=0;
            for(int i=1;i<=n;i++) if(((x-i)&1)==0) g=gcd(g,a[i]);
            bool ok=1;
            for(int i=1;i<=n;i++) if(((x-i)&1)==1) ok&=((a[i]%g)!=0);
            if(ok) d=g;
        }
        cout << d << "\n";
    }
    return 0;
}
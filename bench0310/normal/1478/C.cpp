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
        vector<ll> d(2*n+1,0);
        for(int i=1;i<=2*n;i++) cin >> d[i];
        sort(d.begin(),d.end());
        bool ok=1;
        for(int i=1;i<=2*n;i+=2) ok&=(d[i]==d[i+1]);
        vector<ll> a(n+1,0);
        ll now=0;
        for(ll i=2*n;i>=n+1;i--)
        {
            ll r=(d[2*i-2*n]-2*now);
            if(r%(2*i-2*n)) ok=0;
            a[i-n]=(r/(2*i-2*n));
            now+=a[i-n];
            ok&=(a[i-n]>0);
        }
        for(int i=1;i<n;i++) ok&=(a[i]<a[i+1]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
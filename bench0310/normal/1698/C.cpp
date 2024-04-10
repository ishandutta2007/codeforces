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
        map<ll,int> m;
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            m[a]++;
        }
        vector<ll> a;
        for(auto [b,c]:m) for(int i=1;i<=min(c,3);i++) a.push_back(b);
        n=a.size();
        if(n<8)
        {
            bool ok=1;
            for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) ok&=m.contains(a[i]+a[j]+a[k]);
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
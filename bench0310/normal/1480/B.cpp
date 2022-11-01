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
        ll a,b;
        int n;
        cin >> a >> b >> n;
        vector<array<ll,2>> v(n);
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) cin >> v[i][j];
        sort(v.begin(),v.end());
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            auto [c,d]=v[i];
            b-=(((d+a-1)/a)*c);
            if(b+c<0) ok=0;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
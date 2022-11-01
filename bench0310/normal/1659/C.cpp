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
        int n,a,b;
        cin >> n >> a >> b;
        vector<ll> x(n+1,0);
        for(int i=1;i<=n;i++) cin >> x[i];
        ll res=(1ll<<60);
        ll s=0;
        for(int i=n;i>=0;i--)
        {
            res=min(res,(a+b)*x[i]+(s-(n-i)*x[i])*b);
            s+=x[i];
        }
        cout << res << "\n";
    }
    return 0;
}
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
        ll res=0;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
        {
            ll a,b;
            cin >> a >> b;
            res+=(2*(a+b));
            v[i]=max(a,b);
        }
        ranges::sort(v);
        for(int i=0;i+1<n;i++) res-=(2*v[i]);
        cout << res << "\n";
    }
    return 0;
}
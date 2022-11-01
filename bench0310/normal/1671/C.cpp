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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        ll s=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        ranges::sort(a);
        ll res=0;
        ll d=0;
        for(int i=n;i>=1;i--)
        {
            ll k=max(ll(0),(x+i-s)/i);
            res+=(i*(k-d));
            d=k;
            s-=a[i];
        }
        cout << res << "\n";
    }
    return 0;
}
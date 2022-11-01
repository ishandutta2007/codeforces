#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    int m;
    cin >> m;
    while(m--)
    {
        ll x,y;
        cin >> x >> y;
        int p=lower_bound(a.begin(),a.end(),x)-a.begin();
        ll res=x+y;
        if(p<n) res=min(res,max(ll(0),y-(sum-a[p])));
        if(p-1>=0) res=min(res,x-a[p-1]+max(ll(0),y-(sum-a[p-1])));
        cout << res << "\n";
    }
    return 0;
}
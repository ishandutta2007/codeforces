#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k,x;
    cin >> n >> k >> x;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll> v;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]-a[i]>x) v.push_back((a[i+1]-a[i]-1)/x);
    }
    sort(v.begin(),v.end());
    int res=v.size()+1;
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]<=k)
        {
            res--;
            k-=v[i];
        }
    }
    cout << res << "\n";
    return 0;
}
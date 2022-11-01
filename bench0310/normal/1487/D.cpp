#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll lim=1000000000;
    auto ok=[&](ll x)->bool{return (1<=x&&x<=lim);};
    vector<ll> v;
    for(ll a=1;(a*a-1)/2<=lim;a+=2)
    {
        ll b=(a*a-1)/2;
        ll c=b+1;
        if(a*a+b*b==c*c&&a*a-b==c&&ok(a)&&ok(b)&&ok(c)&&a<=b&&b<=c) v.push_back(c);
    }
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        int l=-1,r=v.size();
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(v[m]<=n) l=m;
            else r=m;
        }
        cout << l+1 << "\n";
    }
    return 0;
}
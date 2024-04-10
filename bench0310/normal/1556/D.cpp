#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    auto q=[&](int i,int j)->ll
    {
        ll r=0;
        cout << "or " << i << " " << j << "\n";
        cout.flush();
        ll t;
        cin >> t;
        r+=t;
        cout << "and " << i << " " << j << "\n";
        cout.flush();
        cin >> t;
        r+=t;
        return r;
    };
    ll x=q(1,2);
    ll y=q(1,3);
    ll z=q(2,3);
    vector<ll> a(n+1,0);
    a[1]=(x-z+y)/2;
    a[2]=x-a[1];
    a[3]=y-a[1];
    for(int i=4;i<=n;i++) a[i]=q(1,i)-a[1];
    sort(a.begin(),a.end());
    cout << "finish " << a[k] << "\n";
    cout.flush();
    return 0;
}
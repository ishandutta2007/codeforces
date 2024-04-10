#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    ll sum=0,a,ma=0;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
        sum+=a;
        ma=max(ma,a);
    }

    sort(v.rbegin(),v.rend());

    bool ok=1;
    ll pl=0,mi=1e9;
    for(ll i=0;i<m;i++)
    {
        cin >> a;
        if(a<ma)
            ok=0;
        pl+=a-ma;
        mi=min(mi,a);
    }

    if(ok)
        db(sum*m+pl+((v[0]-v[1])*(mi!=ma)))
    else
        db(-1)

    return 0;
}
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
#define MAXN 100005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,q;
    cin >> n >> q;
    ll ma=-1;
    vector<pii> ini;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        if(i)
            ini.push_back(pii(ma,a[i]));
        ma=max(ma,a[i]);
    }

    vector<ll> v;
    ll mi=-1,p=0;
    for(ll i=0;i<n;i++)
    {
        if(mi==ma)
            v.push_back(a[i]);
        if(mi!=ma && a[i]==ma)
            p=i;
        mi=max(mi,a[i]);
    }

    mi=-1;
    for(ll i=0;i<=p-1;i++)
    {
        mi=max(mi,a[i]);
        if(i!=p-1)
            v.push_back(min(mi,a[i+1]));
        else
            v.push_back(mi);
    }

    while(q--)
    {
        ll m;
        cin >> m;
        m--;
        if(m<(n-1))
            cout << ini[m].first << ' ' << ini[m].second << '\n';
        else
        {
            m-=p;
            m%=(n-1);
            cout << ma << ' ' << v[m] << '\n';
        }
    }

    return 0;
}
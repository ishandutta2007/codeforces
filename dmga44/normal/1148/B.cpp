#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

ll a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]+=ta;
    }
    vector<pii> v;
    for(ll i=0;i<m;i++)
    {
        cin >> b[i];
        v.push_back(pii(b[i],i));
    }

    ll res=0;
    bool ok=(k>=min(n,m));
    for(int i=0;i<=k;i++)
    {
        ll p=lower_bound(v.begin(),v.end(),pii(a[i]-1,MAXN))-v.begin();
        if(i+m-p<=k)
        {
            ok=1;
            break;
        }
        res=max(res,v[p+k-i].first+tb);
    }
    if(!ok)
        db(res)
    else
        db(-1)

    return 0;
}
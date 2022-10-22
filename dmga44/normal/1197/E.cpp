#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 600005
#define mod (ll(1e9+7))

map<int,int> m,im;
pii res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y;
    cin >> n;
    vector<pii> v;
    set<ll> s;
    s.insert(0);
    s.insert(1e9+1);
    int ma=0;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        ma=max(ma,y);
        v.push_back(pii(x,y));
        s.insert(x);
        s.insert(y);
    }

    sort(v.rbegin(),v.rend());

    int cont=0;
    for(auto y : s)
    {
        m[y]=cont;
        im[cont]=y;
        cont++;
    }

    for(int i=0;i<MAXN;i++)
        res[i]=pii(mod,0);

    int l=cont-1;
    for(int i=0;i<n;i++)
    {
        x=v[i].first;
        y=v[i].second;
        int mx=m[x];
        int my=m[y];
        while(l>0 && im[l]>x)
        {
            ll v1=res[l].first;
            ll cant=res[l].second;
            ll dif=im[l]-im[l-1];
            if(res[l-1].first>v1+dif)
                res[l-1]=pii(v1+dif,cant);
            else if(res[l-1].first==v1+dif)
                res[l-1].second=(res[l-1].second+cant)%mod;
            l--;
        }
        if(x>ma)
        {
            if(!res[my].first)
                res[my].second++;
            else
                res[my]=pii(0,1);
        }
        else
        {
            if(res[my].first>res[mx].first)
                res[my]=res[mx];
            else if(res[my].first==res[mx].first)
                res[my].second=(res[my].second+res[mx].second)%mod;
        }
    }
    while(l>0)
    {
        ll v1=res[l].first;
        ll cant=res[l].second;
        ll dif=im[l]-im[l-1];
        if(res[l-1].first>v1+dif)
            res[l-1]=pii(v1+dif,cant);
        else if(res[l-1].first==v1+dif)
            res[l-1].second=(res[l-1].second+cant)%mod;
        l--;
    }
    db(res[0].second)

    return 0;
}
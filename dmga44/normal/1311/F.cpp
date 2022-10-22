#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

pii abi[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p].first+=v;
        abi[p].second++;
        p+=(p&-p);
    }
}

pii query(int p)
{
    pii res={0,0};
    while(p)
    {
        res.first+=abi[p].first;
        res.second+=abi[p].second;
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> x(n),v(n);
    vector<pii> xv(n);
    set<int> vs;
    map<int,int> m;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        vs.insert(v[i]);
        xv[i]=pii(x[i],v[i]);
    }

    sort(xv.begin(),xv.end());

    int cont=1;
    for(auto y : vs)
    {
        m[y]=cont;
        cont++;
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        xv[i].second=m[xv[i].second];
        pii r1=query(xv[i].second);
        res+=(r1.second*xv[i].first-r1.first);
        update(xv[i].second,xv[i].first);
    }
    db(res)


    return 0;
}
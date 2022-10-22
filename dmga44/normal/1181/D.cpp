#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 500005
#define oo (2e18)

ll abi[MAXN],res[MAXN],f[MAXN],ac[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,q,x;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        f[x]++;
    }

    vector<pii> c;
    for(int i=1;i<=m;i++)
        c.push_back(pii(f[i],i));

    sort(c.begin(),c.end());

    for(int i=0;i<m;i++)
        ac[i+1]=ac[i]+c[i].first;

    vector<pii> qs;
    for(int i=0;i<q;i++)
    {
        cin >> x;
        qs.push_back(pii(x,i));
    }

    sort(qs.begin(),qs.end());

    ll p=0;
    for(ll i=0;i<q;i++)
    {
        ll pos=qs[i].second;
        x=qs[i].first;
        x-=n;
        ll raun=0;
//        db("")
//        db(x)
        for(ll j=(1ll<<60);j;j>>=1)
        {
            ll attem=raun+j;
            if(oo/attem<=m)
                continue;
            ll ppp=lower_bound(c.begin(),c.end(),pii(attem,m+1))-c.begin();
            ll acum=ac[ppp]+((m-ppp)*(attem));
//            db(attem)
//            db(ppp)
//            db(acum)
//            db("")
            if((attem*m-acum)<x)
                raun=attem;
        }

        ll ppp=lower_bound(c.begin(),c.end(),pii(raun,m+1))-c.begin();
        ll acum=ac[ppp]+((m-ppp)*raun);
        x-=(raun*m-acum);
        raun++;
//        db(x)
//        db(raun)
        while(p<m && c[p].first<raun)
        {
            update(c[p].second,1);
            p++;
        }

        ll rrr=0;
        acum=0;
        for(int j=(1<<19);j;j>>=1)
            if(rrr+j<=m && acum+abi[rrr+j]<x)
            {
                rrr+=j;
                acum+=abi[rrr];
            }
        rrr++;
        res[pos]=rrr;
    }

    for(int i=0;i<q;i++)
        db(res[i])

    return 0;
}
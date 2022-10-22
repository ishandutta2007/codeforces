#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1000005

int p[MAXN],mk[MAXN],a[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;

}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x);
    if(e&1)
        x=(x*b);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<ll,ll> m;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
            mk[a[i]]=1;
            v.push_back(a[i]);
            ll pr=-1,e=0;
            while(a[i]!=1)
            {
                if(pr!=p[a[i]])
                    pr=p[a[i]],e=1;
                else
                    e++;
                m[pr]=max(m[pr],e);
                a[i]/=pr;
            }
        }

        vector<pii> fac;
        for(auto y : m)
            fac.push_back(pii(y.first,y.second));

        ll res=1,oo=1e15;
        for(auto y : fac)
        {
            if(fac.size()==1)
                y.second++;
            if(res<oo/qp(y.first,y.second) && res>0)
                res*=qp(y.first,y.second);
            else
                res=-1;
        }

        if(res!=-1)
        {
            vector<ll> divs,aux;
            divs.push_back(1);
            for(auto y : fac)
            {
                ll po=1;
                for(ll i=0;i<=y.second;i++)
                {
                    for(auto x : divs)
                        aux.push_back(x*po);
                    po*=y.first;
                }

                divs.clear();
                for(auto x : aux)
                    divs.push_back(x);
                aux.clear();
            }

            ll ok=1;
            if(res<MAXN && mk[res])
                ok=0;
            for(auto y : divs)
                if(y!=1 && y!=res)
                    ok&=(y<MAXN && mk[y]);
            if(!ok)
                res=-1;
        }
        db(res)

        for(auto y : v)
            mk[y]=0;
    }

    return 0;
}
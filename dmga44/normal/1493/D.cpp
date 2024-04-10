#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

map<pii,int> me;
set<pii> se[MAXN];
vector<pii> de[MAXN];
int p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
    for(int i=2;i<MAXN;i++)
    {
        int e=0;
        int ii=i;
        while(ii%p[i]==0)
        {
            e++;
            ii/=p[i];
        }
        for(auto x : de[ii])
            de[i].push_back(x);
        de[i].push_back(pii(p[i],e));
    }
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n,q,x;
    cin >> n >> q;
    ll g=1;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        for(auto p : de[x])
        {
            se[p.f].insert(pii(p.s,i));
            me[pii(i,p.f)]=p.s;
            if(se[p.f].size()==n)
                g=(g*qp(p.f,(*se[p.f].begin()).f))%mod;
        }
    }

    while(q--)
    {
        int i,x;
        cin >> i >> x;
        i--;
        for(auto pp : de[x])
        {
            int p=pp.f;
            int e=pp.s;
            int v=me[pii(i,p)];
            if(v)
            {
                if(se[p].size()==n)
                    g=(g*qp(qp(p,(*se[p].begin()).f),mod-2))%mod;
                se[p].erase(pii(v,i));

                v+=e;
                me[pii(i,p)]=v;
                se[p].insert(pii(v,i));
                if(se[p].size()==n)
                    g=(g*qp(p,(*se[p].begin()).f))%mod;
            }
            else
            {
                me[pii(i,p)]=e;
                se[p].insert(pii(e,i));
                if(se[p].size()==n)
                    g=(g*qp(p,(*se[p].begin()).f))%mod;
            }
        }
        db(g)
    }

    return 0;
}
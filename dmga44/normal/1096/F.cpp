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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int abi[MAXN];
bool mk[MAXN];

void update(int p)
{
    while(p<MAXN)
    {
        abi[p]++;
        p+=(p&-p);
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

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    ll m1=0;
    ll invs=0;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        if(p[i]==-1)
            m1++;
        else
        {
            invs+=(i-m1-query(p[i]));
            update(p[i]);
            mk[p[i]]=1;
        }
    }

    vector<int> fal;
    for(int i=1;i<=n;i++)
        if(!mk[i])
            fal.push_back(i);

    ll m2=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]!=-1)
        {
            ll b=m1-m2;
            ll x1=lower_bound(all(fal),p[i])-fal.begin();
            ll x2=m1-x1;
            invs=(invs+(((x1*b)%mod)*qp(m1,mod-2)))%mod;
            invs=(invs+(((x2*m2)%mod)*qp(m1,mod-2)))%mod;
        }
        else
            m2++;
    }

    for(int i=2;i<=m1;i++)
        invs=(invs+(i-1)*qp(2,mod-2))%mod;
    db(invs)

    return 0;
}
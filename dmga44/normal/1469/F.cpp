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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<ll> a;

bool solve(ll lim,ll cant)
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(pii(0,0));
    ll act=1;
    int pos=0;
    while(act<cant && !pq.empty() && pos<a.size())
    {
        pii x=pq.top();
        pq.pop();

        int lvl=x.f;
        if(lvl+2>lim)
            continue;
        int cant=x.s;
        if(cant)
        {
            cant--;
            pq.push(pii(lvl+1,cant));
        }
        int sz=a[pos];
        pos++;
        ll best=sz-2;
        best=min(best,2*(lim-lvl-1)-1);
        act+=best;
        int m1=(sz-1)/2-1;
        int m2=sz/2-1;
        pq.push(pii(lvl+2,m1));
        pq.push(pii(lvl+2,m2));
    }
//    db(act)
    return act>=cant;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        sum+=x;
    }
    sort(allr(a));

    if(sum+1-2*n<k)
    {
        db(-1)
        return 0;
    }

//    db(solve(1,k))
//    db(solve(2,k))
//    db(solve(3,k))
//    db(solve(4,k))

    int res=0;
    for(int po=(1<<20);po;po>>=1)
        if(!solve(res+po,k))
            res+=po;
    res++;
    db(res)

    return 0;
}
/**
3 3
4 3 3
**/
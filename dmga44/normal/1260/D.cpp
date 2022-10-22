#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> a;
vector<pip> ts;
int m,n,k,t;

int solve(int x)
{
    int mi=a[x-1];
    vector<pii> lr;
    for(int i=0;i<k;i++)
        if(ts[i].f>mi)
        {
            lr.push_back(pii(ts[i].s.f,1));
            lr.push_back(pii(ts[i].s.s,2));
        }

    sort(all(lr));

    ll res=n+1;
    int last=0;
    int ac=0;
    for(auto y : lr)
    {
        if(y.s==1)
        {
            if(ac==0)
                last=y.f;
            ac++;
        }
        else
        {
            ac--;
            if(ac==0)
                res+=(y.f-last+1)*2;
        }
    }
//    cout << x << ' ' << res << '\n';
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k >> t;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for(int i=0;i<k;i++)
    {
        int l,r,d;
        cin >> l >> r >> d;
        ts.push_back(pip(d,pii(l,r)));
    }

    sort(allr(a));
    sort(all(ts));

    int res=0;
    for(int po=(1<<17);po;po>>=1)
        if(res+po<=m && solve(res+po)<=t)
            res+=po;
    db(res)

    return 0;
}
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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

bool ask(int i,int j)
{
    cout << "? " << i+1 << ' ' << j+1 << '\n';
    cout.flush();
    string kk;
    cin >> kk;
    return (kk=="Yes");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pip> ts;
    vector<int> g;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        g.push_back(x);
    }

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ts.push_back(pip(abs(g[i]-g[j]),pii(i,j)));

    sort(allr(ts));

    pii res=pii(0,0);
    for(int i=0;i<ts.size();i++)
    {
        int u=ts[i].s.f;
        int v=ts[i].s.s;
        int v1=g[u];
        int v2=g[v];
        if(v2-v1-1>=0)
        {
            if(ask(v,u))
            {
                res=pii(u+1,v+1);
                break;
            }
        }
        else if(v1-v2-1>=0)
        {
            if(ask(u,v))
            {
                res=pii(v+1,u+1);
                break;
            }
        }
        else if(v2==v1)
        {
            res=pii(v+1,u+1);
            break;
        }
    }

    cout << "! " << res.f << ' ' << res.s << '\n';

    return 0;
}
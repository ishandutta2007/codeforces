#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

vector<pip> g[MAXN];
vector<ll> v1;
vector<ll> ac1;
vector<ll> v2;
vector<ll> ac2;
ll sum;
bool mk[MAXN];

int dfs(int u)
{
    mk[u]=1;
    ll cant=0;
    for(auto y : g[u])
    {
        ll v=y.f;
        ll w=y.s.f;
        ll c=y.s.s;
        if(mk[v])
            continue;

        ll x=dfs(v);

        sum+=x*w;
        vector<ll> *it=&v1;
        if(c==2)
            it=&v2;

        while(w)
        {
            (*it).push_back(x*(w-(w/2)));
            w/=2;
        }
        cant+=x;
    }
    if(!cant)
        cant++;
    return cant;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,s;
        cin >> n >> s;
        v1.clear();
        ac1.clear();
        v2.clear();
        ac2.clear();
        sum=0;
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            mk[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            ll u,v,w,c;
            cin >> u >> v >> w >> c;
            u--,v--;
            g[u].push_back(pip(v,pii(w,c)));
            g[v].push_back(pip(u,pii(w,c)));
        }

        dfs(0);

//        db(sum)
//        db(s)
        sort(allr(v1));
        sort(allr(v2));
        ac1.push_back(0);
        ac2.push_back(0);
        for(auto y : v1)
            ac1.push_back(ac1.back()+y);
        for(auto y : v2)
            ac2.push_back(ac2.back()+y);

        ll res=1e10;
        for(int i=0;i<ac1.size();i++)
        {
            ll x=sum-ac1[i];
            ll faltan=x-s;
            ll pos=lower_bound(all(ac2),faltan)-ac2.begin();
            if(pos!=ac2.size())
                res=min(res,i+2*pos);
        }
        db(res)
    }

    return 0;
}
/**
4
4 18
2 1 9 2
3 2 4 1
4 1 1 2
3 20
2 1 8 1
3 1 7 2
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1
2 100
1 2 409 2
**/
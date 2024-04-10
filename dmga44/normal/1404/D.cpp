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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<pii> g[MAXN];
bool mk[MAXN];
vector<int> vals;
vector<int> ps[MAXN];
bool mkid[MAXN];
int ini;
int n;

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
    {
        int v=y.f;
        int id=y.s;
        if(!mkid[id])
        {
            mkid[id]=1;
            if(ps[id][0]%n==u)
            {
                vals.push_back(ps[id][0]);
                vals.push_back(ps[id][1]);
            }
            else
            {
                vals.push_back(ps[id][1]);
                vals.push_back(ps[id][0]);
            }
        }
        if(mk[v])
            continue;
        dfs(v);
    }
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n;
    if(n&1)
    {
        cout << "Second\n";
        cout.flush();
        for(int i=0;i<2*n;i++)
        {
            int x;
            cin >> x;
            x--;
            if(ps[x].size())
            {
                g[(i+1)%n].push_back(pii(ps[x].back()%n,x));
                g[ps[x].back()%n].push_back(pii((i+1)%n,x));
            }
            ps[x].push_back(i+1);
        }

        vector<int> untie;
        ll sum=0;
        set<int> res;
        for(int i=0;i<n;i++)
        {
            if(mk[i])
                continue;
            dfs(i);
            if((vals.size()/2)&1)
                untie=vals;
            for(int j=0;j<vals.size();j+=2)
            {
                sum+=vals[j];
                res.insert(vals[j]);
            }
            vals.clear();
        }

        if(sum%(2*n))
        {
            for(int j=1;j<untie.size();j+=2)
            {
                res.insert(untie[j]);
                res.erase(untie[j-1]);
            }
        }

        for(auto y : res)
            cout << y << ' ';
        cout << '\n';
        cout.flush();
        int x;
        cin >> x;

    }
    else
    {
        cout << "First\n";
        cout.flush();
        for(int i=0;i<2*n;i++)
            cout << (i%n)+1 << ' ';
        cout<<'\n';
        cout.flush();
        int x;
        cin >> x;
    }

    return 0;
}
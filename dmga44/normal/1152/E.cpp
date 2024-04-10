#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
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
#define MAXN (ll)(1e5+5)

int b[MAXN],c[MAXN],tt[MAXN],fs[MAXN];
vector< vector<pii> > g;

vector<int> euler_path(const vector<vector<pair<int, int>>> &G, int s = 0)
{
    int n = G.size(), odd = 0, m = 0;
    for (int i = 0; i < n; ++i)
    {
        odd += G[i].size() & 1;
        m += G[i].size();
    }

    vector<int> path;
    if (odd == 0 || (odd == 2 && (G[s].size() & 1) == 1))
    {
        vector<int> pos(n);
        vector<bool> mark(m / 2);
        function<void(int)> visit = [&](int u) {

            for (int v, id; pos[u] < G[u].size();)
            {
                tie(v, id) = G[u][pos[u]++];
                if (!mark[id])
                {
                    mark[id] = true;
                    visit(v);
                }
            }
            path.push_back(u);
        };
        visit(s);
        reverse(path.begin(), path.end());

        if (path.size() != m / 2 + 1)
            path.clear();
    }
    return path;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
        cin >> b[i];
    for(int i=0;i<n-1;i++)
        cin >> c[i];

    bool ok=1;
    set<int> s;
    for(int i=0;i<n-1;i++)
    {
        ok&=(c[i]>=b[i]);
        s.insert(c[i]);
        s.insert(b[i]);
    }
    if(!ok)
    {
        db(-1)
        return 0;
    }
    int cont=0;
    map<int,int> t;
    for(auto y : s)
    {
        t[y]=cont;
        tt[cont]=y;
        cont++;
    }

    g.resize(cont);
    for(int i=0;i<n-1;i++)
    {
        b[i]=t[b[i]];
        c[i]=t[c[i]];
        fs[b[i]]++;
        fs[c[i]]++;
        g[b[i]].push_back(pii(c[i],i));
        g[c[i]].push_back(pii(b[i],i));
    }

    int ini=0;
    for(int i=0;i<cont;i++)
        if(fs[i]&1)
            ini=i;

    vector<int> res=euler_path(g,ini);

    if(res.size()==0)
        db(-1)
    else
    {
        for(auto y : res)
            cout << tt[y] << ' ';
        cout << '\n';
    }

    return 0;
}
/**
5
4 5 3 5
6 7 4 6
**/
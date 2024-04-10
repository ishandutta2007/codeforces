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
#define MAXN (ll)(2e3+5)

vector<pii> us[MAXN];
int dp[MAXN];
vector<int> g1[MAXN];
int leaves1[MAXN];
int p1[MAXN];
int sons1[MAXN];
bool mk1[MAXN];
vector<int> g2[MAXN];
int leaves2[MAXN];
int p2[MAXN];
int sons2[MAXN];
bool mk2[MAXN];

vector<int> dfs(int u,vector<int>* g,int* leaves,int* sons,bool* mk)
{
    mk[u]=1;
    sons[u]=1;
    vector<int> lx;
    for(auto v : g[u])
        if(!mk[v])
        {
            vector<int> vp=dfs(v,g,leaves,sons,mk);
            us[vp[0]].push_back(pii(sons[v],vp.back()+1));
            sons[u]+=sons[v];
            for(auto y : vp)
                lx.push_back(y);
        }

    if(!lx.size())
    {
        lx.push_back(leaves[u]);
        return lx;
    }

    sort(all(lx));

    return lx;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sz1;
    cin >> sz1;
    for(int i=0;i<sz1-1;i++)
    {
        cin >> p1[i+1];
        p1[i+1]--;
        g1[i+1].push_back(p1[i+1]);
        g1[p1[i+1]].push_back(i+1);
    }

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        x--;
        leaves1[x]=i;
    }

    int sz2;
    cin >> sz2;
    for(int i=0;i<sz2-1;i++)
    {
        cin >> p2[i+1];
        p2[i+1]--;
        g2[i+1].push_back(p2[i+1]);
        g2[p2[i+1]].push_back(i+1);
    }

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        x--;
        leaves2[x]=i;
    }

    dfs(0,g1,leaves1,sons1,mk1);
    dfs(0,g2,leaves2,sons2,mk2);

    for(int i=0;i<n;i++)
        for(auto y : us[i])
            dp[y.s]=max((ll)dp[y.s],dp[i]+y.f);
    db(dp[n])

    return 0;
}
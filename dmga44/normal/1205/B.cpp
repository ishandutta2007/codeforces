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

vector<int> hs[60];
vector<int> g[MAXN];
vector<int> nodes;
bool mk[MAXN];
int level[MAXN];
int parent[MAXN];

void dfs(int u)
{
    mk[u]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk[v])
            dfs(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        for(int p=0;p<60;p++)
            if(x&(1ll<<p))
                hs[p].push_back(i);
    }

    int res=oo;
    for(int i=0;i<60;i++)
    {
        if(hs[i].size()>=3)
            res=3;
        if(hs[i].size()<2)
            continue;
        g[hs[i][0]].push_back(hs[i][1]);
        g[hs[i][1]].push_back(hs[i][0]);
    }

    for(int i=0;i<n;i++)
    {
        if(mk[i])
            continue;
        dfs(i);

        for(int j=0;j<nodes.size();j++)
        {
            int r=nodes[j];
            for(auto v : nodes)
            {
                level[v]=-1;
                parent[v]=-1;
            }

            level[r]=0;
            queue<int> q;
            q.push(r);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();

                for(auto v : g[u])
                {
                    if(v==parent[u])
                        continue;
                    if(level[v]==-1)
                    {
                        parent[v]=u;
                        level[v]=level[u]+1;
                        q.push(v);
                    }
                    else if(u!=parent[v])
                        res=min(res,level[u]+level[v]+1);
                }
            }
        }

        nodes.clear();
    }
    if(res==oo)
        db(-1)
    else
        db(res)

    return 0;
}
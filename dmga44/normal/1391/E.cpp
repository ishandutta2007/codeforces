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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
int lvl[MAXN],p[MAXN];
bool mk[MAXN];
int cant[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        p[v]=u;
        lvl[v]=lvl[u]+1;
        cant[u]++;
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        p[0]=-1;
        dfs(0);

        priority_queue<pii,vector<pii>,less<pii> > pq;
        for(int i=0;i<n;i++)
            if(!cant[i])
                pq.push(pii(lvl[i],i));
        vector<pii> pairs;
        while(pq.size()>=2)
        {
            int u=pq.top().s;
            pq.pop();
            int v=pq.top().s;
            pq.pop();
            pairs.push_back(pii(u,v));

            cant[p[u]]--;
            if(!cant[p[u]])
                pq.push(pii(lvl[p[u]],p[u]));
            cant[p[v]]--;
            if(!cant[p[v]])
                pq.push(pii(lvl[p[v]],p[v]));
        }

        if(pairs.size()*4>=n)
        {
            db("PAIRING")
            db(pairs.size())
            for(auto y : pairs)
                cout << y.f+1 << ' ' << y.s+1 << '\n';
        }
        else
        {
            vector<int> res;
            while(!pq.empty())
            {
                int u=pq.top().s;
                pq.pop();
                res.push_back(u);
                if(p[u]!=-1)
                    pq.push(pii(p[u],p[u]));
            }
            db("PATH")
            db(res.size())
            for(auto y : res)
                cout << y+1 << ' ';
            cout << '\n';
        }

        for(int i=0;i<n;i++)
        {
            g[i].clear();
            mk[i]=0;
            p[i]=cant[i]=lvl[i]=0;
        }
    }

    return 0;
}
/**
4
6 5
1 4
2 5
3 6
1 5
3 5
6 5
1 4
2 5
3 6
1 5
3 5
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3
**/
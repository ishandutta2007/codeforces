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
#define mod (ll)(1e6+3)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int c[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    for(int i=0;i<n;i++)
    {
        q.push(i);
        mk[i]=1;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        mk[u]=0;
        int cant=0;
        for(auto v : g[u])
            if(c[v]==c[u])
                cant++;
        if(cant>1)
        {
            c[u]=1-c[u];
            for(auto v : g[u])
                if(!mk[v])
                {
                    q.push(v);
                    mk[v]=1;
                }
        }
    }

    for(int i=0;i<n;i++)
        cout << c[i];
    cout << '\n';

    return 0;
}
/**
3 3
1 2
3 2
1 3

10 6
1 2
1 3
1 4
2 3
2 4
3 4

10 12
10 1
3 8
9 1
6 9
7 1
3 5
10 7
7 3
8 5
5 9
10 4
8 6
**/
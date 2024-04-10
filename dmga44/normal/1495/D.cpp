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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e2+5)

vector<int> g[MAXN];
int d[MAXN][MAXN];
int ans[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    for(int i=0;i<n;i++)
    {
        vector<bool> mk(n);
        queue<int> q;
        q.push(i);
        mk[i]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto v : g[u])
                if(!mk[v])
                {
                    mk[v]=1;
                    q.push(v);
                    d[i][v]=d[i][u]+1;
                }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int r1=i;
            int r2=j;
            if(r1==r2)
            {
                ll res=1;
                for(int u=0;u<n;u++)
                {
                    if(u==r1)
                        continue;
                    ll mul=0;
                    for(auto v : g[u])
                        if(d[r1][u]==d[r1][v]+1)
                            mul++;
                    res=(res*mul)%mod;
                }
                ans[i][j]=res;
                continue;
            }

            vector<int> inter;
            queue<int> q;
            vector<bool> mk(n);
            q.push(r1);
            mk[r1]=1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                inter.push_back(u);
                if(!d[r2][u])
                    continue;
                for(auto v : g[u])
                    if(d[r2][v]<d[r2][u])
                    {
                        mk[v]=1;
                        q.push(v);
                    }
            }
            if(inter.size()>d[r1][r2]+1)
            {
                ans[r1][r2]=0;
                continue;
            }
            ll res=1;
            for(int u=0;u<n;u++)
            {
                if(mk[u])
                    continue;
                ll mul=0;
                for(auto v : g[u])
                    if(d[r1][u]==d[r1][v]+1 && d[r2][u]==d[r2][v]+1)
                        mul++;
                res=(res*mul)%mod;
            }
            ans[i][j]=res;
        }

    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<n;j++)
            cout << ans[i][j] << ' ';

    return 0;
}
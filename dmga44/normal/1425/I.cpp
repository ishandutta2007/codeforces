#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX
//#pragma GCC optimize("03")

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
#define MAXN (ll)(1e5+5)

int a[MAXN];
int t[MAXN];
vector<int> g[MAXN];
int lvl[MAXN];
bool mk[MAXN];
int li[MAXN],ls[MAXN];
int ip[MAXN];
int cont;
int px[MAXN];
int aa[MAXN];
int lvll[MAXN];

void dfs(int u)
{
    mk[u]=1;
    li[u]=cont;
    ip[cont]=u;
    px[cont]=u;
    cont++;
    for(auto v : g[u])
        if(!mk[v])
        {
            lvl[v]=lvl[u]+1;
            dfs(v);
        }
    ls[u]=cont;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    dfs(0);

    for(int i=0;i<n;i++)
    {
        aa[i]=a[ip[i]];
        lvll[i]=lvl[ip[i]];
    }

    for(int i=0;i<q;i++)
    {
        int r1=0;
        int r2=0;
        int u;
        cin >> u;
        u--;
        for(int j=li[u];j<ls[u];j++)
            if(t[j]<=i)
            {
                r1++;
                r2+=lvll[j];
                t[j]=i+aa[j];
            }
        r2-=r1*lvl[u];
        cout << r2 << ' ' << r1 << '\n';
    }
    return 0;
}
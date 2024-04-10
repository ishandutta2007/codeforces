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
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)
#define kk (ll)(512)

vector<int> gg[MAXN];
vector<int> ig[MAXN];
int f[MAXN];
int g[MAXN];
int cant[MAXN];
ll ma;

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

void mex(int u)
{
    for(auto y : gg[u])
        f[g[y]]++;
    g[u]=0;
    while(f[g[u]])
        g[u]++;
    for(auto y : gg[u])
        f[g[y]]--;
}

int GAUSSIAN_ELIMINATION(vector<vector<ll>> A, vector<ll> &ans, const ll MOD)
{
    const int INF = 2;

    int N = (int)A.size();
    int M = (int)A[0].size()-1;

    vector<int> where(M, -1);

    for(int col = 0, row = 0 ; col < M && row < N ; col++)
    {
        for(int i = row ; i < N ; i++)
            if(A[i][col])
            {
                if(i == row)break;
                for(int j = col ; j <= M ; j++)
                    swap(A[i][j], A[row][j]);
                break;
            }

        if(!A[row][col])
            continue;

        where[col] = row;

        ll a = A[row][col], b = MOD-2, c = 1;

        while(b)
        {
            if(b&1)c = c*a%MOD;
            a = a*a%MOD;
            b >>= 1;
        }

        for(int i = col ; i <= M ; i++)
            A[row][i] = A[row][i]*c%MOD;

        for(int i = row+1 ; i < N ; i++)
            if(A[i][col])
            {
                ll c = A[i][col];

                for(int j = col ; j <= M ; j++)
                    A[i][j] = (A[i][j] + MOD - A[row][j]*c%MOD) % MOD;
            }

        row++;
    }

    ans.assign(M, 0);

    vector<ll> vect(N);

    for(int i = 0 ; i < N ; i++)
        vect[i] = A[i][M];

    for(int j = M-1 ; j >= 0 ; j--)
    {
        if(where[j] != -1)
            ans[j] = vect[where[j]];

        for(int i = 0 ; i < N ; i++)
            vect[i] = (vect[i] + MOD - ans[j]*A[i][j]%MOD) % MOD;
    }

    for(int i = 0 ; i < N ; i++)
    {
        ll sum = 0;

        for(int j = 0 ; j < M ; j++)
            sum = (sum + ans[j]*A[i][j]) % MOD;

        if(sum != A[i][M])
            return 0;
    }

    for(int i = 0 ; i < M ; i++)
        if(where[i] == -1)
            return INF;

    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        cant[u]++;
        gg[u].push_back(v);
        ig[v].push_back(u);
    }

    queue<int> q;
    for(int i=0;i<n;i++)
        if(!cant[i])
            q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        mex(u);
        ma=max(ma,(ll)g[u]);
        for(auto v : ig[u])
        {
            cant[v]--;
            if(!cant[v])
                q.push(v);
        }
    }
    ma++;
    while((ma&-ma)!=ma)
        ma+=(ma&-ma);

    vector<ll> f(ma);
    for(int i=0;i<n;i++)
        f[g[i]]++;

    vector<vector<ll>> a(ma,vector<ll>(ma+1));
    for(int i=0;i<ma;i++)
    {
        a[i][i]=mod-1;
        if(i)
            a[i][ma]=(mod-qp(n+1,mod-2));
        for(int j=0;j<ma;j++)
            a[i][j]=(a[i][j]+f[j^i]*qp(n+1,mod-2))%mod;
    }

    vector<ll> res;
    int _=GAUSSIAN_ELIMINATION(a,res,mod);
    db(res[0])

    return 0;
}
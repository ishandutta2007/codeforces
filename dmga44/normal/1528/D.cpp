#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

vector<int> bests(int n,vector<pii>& ps,int t)
{
    vector<int> ans(n,oo);
    int p=0;
    for(auto y : ps)
    {
        ans[(y.first+t)%n]=y.second;
        if(ans[(y.first+t)%n]<ans[p])
            p=(y.first+t)%n;
    }

    for(int i=1;i<n;i++)
        ans[(p+i)%n]=min(ans[(p+i)%n],ans[(p+i-1)%n]+1);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<pii> g[n];
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].push_back(pii(v,c));
    }

    for(int i=0;i<n;i++)
    {
        vector<ll> base=bests(n,g[i],0);
        // db("")
        // db(i)
        // for(auto y : base)
        //     cout << y << ' ';
        // cout << '\n';
        ll mi=base[0];
        for(int j=0;j<n;j++)
            mi=min(mi,base[j]);
        vector<int> ans(n);
        for(int j=0;j<n;j++)
            base[j]-=mi;
        ans[i]-=mi;
        vector<vector<bool>> mk(n+1,vector<bool>(n+1));
        for(int j=0;j<n;j++)
            if(i!=j)
                mk[base[j]][j]=1;
        vector<bool> passed(n);
        passed[i]=1;
        for(int j=0;j<=n;j++)
        {
            for(int u=0;u<n;u++)
            {
                if(passed[u] || !mk[j][u])
                    continue;
                ans[u]=j;
                passed[u]=1;

                vector<int> adds=bests(n,g[u],mi+j);
                // cout << u << ' ' << mi+j << '\n';
                // for(auto y : adds)
                //     cout << y << ' ';
                // cout << '\n';
                for(int v=0;v<n;v++)
                    if(j+adds[v]<=n)
                        mk[j+adds[v]][v]=1;
            }
        }

        for(int j=0;j<n;j++)
            cout << ans[j]+mi << ' ';
        cout << '\n';
    }


    return 0;
}
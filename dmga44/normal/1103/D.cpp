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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<24)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll g=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        g=__gcd(a[i],g);
    }
    vector<ll> e(n);
    for(int i=0;i<n;i++)
        cin >> e[i];

    vector<pii> vp;
    for(int i=0;i<n;i++)
        vp.push_back(pii(e[i],a[i]));

    sort(all(vp));

    vector<ll> ps;
    for(ll i=2;i<1e6+5;i++)
    {
        if(g%i)
            continue;
        while(!(g%i))
            g/=i;
        ps.push_back(i);
    }
    if(g!=1)
        ps.push_back(g);

    if(ps.empty())
    {
        db(0);
        return 0;
    }

    map<ll,ll> fx;
    vector<vector<int> > pos(n);
    vector<int> cant(1<<ps.size());
    vector<ll> mul(1<<ps.size());
    mul[0]=1;
    vector<ll> last(1<<ps.size());
    for(int i=1;i<(1<<ps.size());i++)
        for(int j=0;j<ps.size();j++)
        {
            if(i&(1<<j))
            {
                last[i]=j;
                break;
            }
        }

    for(int i=0;i<n;i++)
    {
        ll x=vp[i].s;
        ll v=vp[i].f;
        ll nv=1;
        for(int j=0;j<ps.size();j++)
        {
            while(x%ps[j]==0)
            {
                nv*=ps[j];
                x/=ps[j];
            }
        }
        fx[nv]++;
        if(fx[nv]>10)
            continue;
        x=nv;
        vector<ll> pieces;
        for(int i=0;i<ps.size();i++)
        {
            ll v=1;
            while(x%ps[i]==0)
            {
                v*=ps[i];
                x/=ps[i];
            }
            pieces.push_back(v);
        }

        for(int mask=1;mask<(1<<ps.size());mask++)
        {
            mul[mask]=mul[mask^(mask&(-mask))]*pieces[last[mask]];
            if(mul[mask]<=k && cant[mask]<10)
            {
                cant[mask]++;
                pos[i].push_back(mask);
            }
        }
    }

    vector<vector<ll>> dp(15,vector<ll>(1<<ps.size()));
    vector<vector<ll>> ndp(15,vector<ll>(1<<ps.size()));
    for(int i=0;i<15;i++)
        for(int j=0;j<(1<<ps.size());j++)
            ndp[i][j]=dp[i][j]=1e18;
    for(int i=0;i<n;i++)
    {
        if(!pos[i].size())
            continue;
        ll v=vp[i].f;
        for(auto mask : pos[i])
        {
            ndp[1][mask]=min(v,dp[1][mask]);
            int c=(1<<ps.size())-1-mask;
            for(int x=2;x<=ps.size();x++)
            {
                for(int j=c;j;j=((j-1)&c))
                {
                    if(dp[x-1][j]==1e18)
                        continue;
                    ndp[x][j|mask]=min(ndp[x][j|mask],dp[x-1][j]+v*x+dp[x-1][j]/(x-1));
                }
            }
        }
        for(int i=0;i<=ps.size();i++)
            for(int j=0;j<(1<<ps.size());j++)
                dp[i][j]=ndp[i][j];
    }
//    for(auto y : ks)
//        cout << y << ' ';
//    cout << '\n';

    ll res=1e18;
    for(int i=0;i<15;i++)
        res=min(res,dp[i][(1<<ps.size())-1]);

    if(res==1e18)
        db(-1)
    else
        db(res)

    return 0;
}
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> d(n+1);
    d[1]=1;
    for(int i=1;i<=n;i++)
        for(int j=2*i;j<=n;j+=i)
            d[j]-=d[i];
    
    vector<ll> xs(n);
    for(int i=0;i<n;i++)
        cin >> xs[i];
    for(int i=0;i<n;i++)
    {
        int v;
        cin >> v;
        xs[i]=v-xs[i];
    }

    for(int i=2;i<=n;i++)
        for(int j=2*i;j<=n;j+=i)
            xs[j-1]-=xs[i-1];

    xs[0]++;

    int q;
    cin >> q;
    vector<pii> qs;
    for(int i=0;i<q;i++)
    {
        int x;
        cin >> x;
        qs.push_back(pii(xs[0]+x,i));
        // cout << i << ' ' << xs[0]+x << '\n';
    }
    // cout << '\n';

    sort(all(qs));

    vector<int> changes;
    ll mul=0,add=0;
    for(int i=1;i<n;i++)
    {
        if(!d[i+1])
            add+=abs(xs[i]);
        else
        {
            mul--;
            add+=(-xs[i]/d[i+1]);
            changes.push_back(-xs[i]/d[i+1]);
            // cout << i << ' ' << -xs[i]/d[i+1] << '\n';
        }
    }
    // cout << '\n';

    sort(all(changes)); 
    
    vector<ll> ans(q);
    int p=0;
    for(int i=0;i<q;i++)
    {
        int id=qs[i].second;
        ll v=qs[i].first;
        while(p<changes.size() && changes[p]<v)
        {
            mul+=2;
            add-=2*changes[p];
            p++;
        }

        // cout << mul << ' ' << add << ' ' << v << '\n'; 
        ans[id]=abs(v)+add+mul*v;
    }

    for(auto v : ans)
        cout << v << '\n';

    return 0;   
}
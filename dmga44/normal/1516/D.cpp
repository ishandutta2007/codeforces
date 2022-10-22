#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> ps[MAXN];
vector<int> pos[MAXN];
int f[MAXN];
int stable[MAXN][19];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(ps[i].empty())
            for(int j=i;j<MAXN;j+=i)
                ps[j].push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(auto p : ps[a[i]])
            pos[p].push_back(i);
    }
    set<pii> sp;
    for(int i=0;i<MAXN;i++)
        if(pos[i].size()>1)
            sp.insert(pii(pos[i][1],i));

    vector<int> lims(n+1);
    if(sp.size())
        lims[0]=(*sp.begin()).f;
    else
        lims[0]=n;
    for(int i=0;i<n;i++)
    {
        for(auto p : ps[a[i]])
        {
            f[p]++;
            if(pos[p].size()>f[p])
                sp.erase(pii(pos[p][f[p]],p));
            if(pos[p].size()>f[p]+1)
                sp.insert(pii(pos[p][f[p]+1],p));
        }
        if(sp.size())
            lims[i+1]=(*sp.begin()).f;
        else
            lims[i+1]=n;
    }
    for(int i=0;i<=n;i++)
    {
//        cout << i << ' ' << lims[i] << '\n';
        stable[i][0]=lims[i];
    }
    for(int j=0;j<18;j++)
        for(int i=0;i<=n;i++)
            stable[i][j+1]=stable[stable[i][j]][j];

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        ll ans=0,act=l;
        for(int i=17;i>=0;i--)
            if(stable[act][i]<r)
            {
                ans+=(1<<i);
                act=stable[act][i];
            }
        ans++;
        db(ans)
    }

    return 0;
}
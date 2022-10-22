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
typedef double ld;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> divs[MAXN];
int occ[MAXN];
int sz_occ;
bool prime[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            divs[j].push_back(i);
    prime[1]=1;
    for(int i=2;i<MAXN;i++)
        if(!prime[i])
            for(int j=2*i;j<MAXN;j+=i)
                prime[j]=1;

    vector<ll> mul(MAXN);
    mul[1]=1;
    for(int i=2;i<MAXN;i++)
    {
        mul[i]=i;
        for(auto d : divs[i])
            if(d!=i)
                mul[i]-=mul[d];
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll ans=0;
    vector<ll> f(MAXN);
    for(int i=1;i<=n;i++)
    {
        sz_occ=0;
        for(int j=i;j<=n;j+=i)
            for(auto d : divs[a[j-1]])
            {
                if(!f[d])
                {
                    occ[sz_occ]=d;
                    sz_occ++;
                }
                f[d]++;
            }
//        db("")
//        db("xxx")
//        db(i)
//        cout << mul[i] << '\n';
        for(int j=0;j<sz_occ;j++)
        {
//            cout << f[occ[j]] << ' ' << occ[j] << '\n';
//            db(mul[occ[j]])
            ans+=f[occ[j]]*f[occ[j]]*mul[occ[j]]*mul[i];
            f[occ[j]]=0;
        }
    }

    db(ans%mod)

    return 0;
}
/**
5
3 6 2 1 4
**/
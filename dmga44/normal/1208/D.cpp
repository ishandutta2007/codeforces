#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll a[MAXN];
int res[MAXN];
ll abi[MAXN];

void update(int p,ll v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        update(i,i);
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=n-1;i>=0;i--)
    {
        ll ac=0;
        ll p=0;
        for(int po=(1<<17);po;po>>=1)
            if(p+po<n && ac+abi[p+po]<=a[i])
            {
                p+=po;
                ac+=abi[p];
            }
        p++;
        res[i]=p;
        update(p,-p);
    }

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';


    return 0;
}
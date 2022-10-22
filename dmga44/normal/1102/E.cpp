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
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int,int> ini;
    map<int,int> fin;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(ini[x]==0)
            ini[x]=i+1;
        fin[x]=i+1;
    }

    vector<pii> orr;
    for(auto y : ini)
        orr.push_back(pii(y.s,1));
    for(auto y : fin)
        orr.push_back(pii(y.s,2));

    sort(all(orr));
    ll res=1;
    int sum=0;
    int cont=0;
    for(auto y : orr)
    {
        if(y.s==1)
        {
            if(sum==0 && cont)
                res=(res*2)%mod;
            sum++;
        }
        else
            sum--;
        cont++;
    }
    db(res)


    return 0;
}
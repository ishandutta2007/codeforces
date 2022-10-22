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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> trans;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            trans[a[i]]=1;
        }

        int cont=0;
        for(auto &y : trans)
        {
            y.s=cont;
            cont++;
        }

        for(int i=0;i<n;i++)
            a[i]=trans[a[i]];

        if(trans.size()>1)
        {
            db("YES")
            vector<int> kk[trans.size()];
            for(int i=0;i<n;i++)
                kk[a[i]].push_back(i);
            vector<pii> res;
            for(int i=0;i<trans.size()-1;i++)
                res.push_back(pii(kk[i][0],kk[i+1][0]));
            for(int i=0;i<trans.size();i++)
            {
                int v=kk[(i+1)%trans.size()][0];
                for(int j=1;j<kk[i].size();j++)
                    res.push_back(pii(v,kk[i][j]));
            }
            for(auto y : res)
                cout << y.f+1 << ' ' << y.s+1 << '\n';
        }
        else
            db("NO")
    }

    return 0;
}
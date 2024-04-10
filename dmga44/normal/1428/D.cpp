//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<pii> res;
    vector<pii> av;
    vector<pii> av3;
    int cont=n;
    bool ok=1;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==0)
            continue;
        if(a[i]==1)
        {
            if(cont==0)
                ok=0;
            res.push_back(pii(cont,i+1));
            av.push_back(pii(cont,i+1));
            cont--;
        }
        if(a[i]==2)
        {
            if(av.empty())
                ok=0;
            else
            {
                pii p=av.back();
                av.pop_back();
                int x=p.f;
                int y=p.s;
                res.push_back(pii(x,i+1));
                av3.push_back(pii(x,i+1));
            }
        }
        if(a[i]==3)
        {
            if(cont==0 || (av.empty() && av3.empty()))
                ok=0;
            else
            {
                if(av3.size())
                {
                    pii p=av3.back();
                    av3.pop_back();
                    int x=p.f;
                    int y=p.s;
                    res.push_back(pii(cont,y));

                    res.push_back(pii(cont,i+1));
                    av3.push_back(pii(cont,i+1));
                    cont--;
                }
                else
                {
                    pii p=av.back();
                    av.pop_back();
                    int x=p.f;
                    int y=p.s;
                    res.push_back(pii(cont,y));

                    res.push_back(pii(cont,i+1));
                    av3.push_back(pii(cont,i+1));
                    cont--;
                }
            }
        }
    }

    if(!ok)
        db(-1)
    else
    {
        db(res.size())
        for(auto y : res)
            cout << y.f << ' ' << y.s << '\n';
    }

    return 0;
}
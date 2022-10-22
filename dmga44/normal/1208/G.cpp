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
#define oo (ll)(1e9+5)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int c[MAXN];
int cant[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    set<pii> s;
    for(int i=3;i<=n;i++)
    {
        c[i]=i-1;
        if(!cant[i])
            s.insert(pii(i-1,i));
        for(int j=2*i;j<=n;j+=i)
            cant[j]++;
    }

    ll res=1;
    for(int i=0;i<k;i++)
    {
        pii x=*s.begin();
        s.erase(x);
        int m=x.f;
        int v=x.s;
        res+=m;
        for(int j=v*2;j<=n;j+=v)
        {
            cant[j]--;
            c[j]-=m;
            if(!cant[j])
                s.insert(pii(c[j],j));
        }
//        cout << v << '\n';
        if(v==4)
        {
            for(int j=6;j<=n;j+=4)
            {
                if(!cant[j])
                {
                    s.erase(pii(c[j],j));
                    c[j]-=1;
                    s.insert(pii(c[j],j));
                }
                else
                    c[j]-=1;
            }
        }
    }
    db(res)

    return 0;
}
/**
1000000 999998
**/
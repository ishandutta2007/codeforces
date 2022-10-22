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
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
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
        vector<ll> p;
        vector<ll> neg;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            if(x>=0)
                p.push_back(x);
            else
                neg.push_back(-x);
        }

        sort(allr(p));
        sort(allr(neg));

        if(neg.size()==n)
        {
            ll res=-1;
            for(int i=0;i<5;i++)
                res*=neg[n-i-1];
            db(res)
            continue;
        }
        ll res=0;
        bool ok=0;
        for(int i=1;i<=5;i+=2)
        {
            ll mul=1;
            if(p.size()>=i && neg.size()>=5-i)
            {
                for(int j=0;j<i;j++)
                    mul*=p[j];
                for(int j=0;j<5-i;j++)
                    mul*=neg[j];
                res=max(res,mul);
                ok=1;
            }
        }
        if(ok)
            db(res)
        else
        {
            ll res=1;
            for(auto y : p)
                res*=y;
            for(auto y : neg)
                res*=-y;
            db(res)
        }
    }

    return 0;
}
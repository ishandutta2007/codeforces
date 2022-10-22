#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<ll,less<ll> > m1; ///arriba
    set<ll,greater<ll> > m2; ///abajo
    set<ll,less<ll> > lght;
    ll sumt=0,sumu=0;
    for(int i=0;i<n;i++)
    {
        int ty,d;
        cin >> ty >> d;
        sumt+=d;
        if(ty)
        {
            if(d>0)
            {
                lght.insert(d);
                m2.insert(d);

                ll v=*(m2.begin());
                sumu+=v;
                m2.erase(v);
                m1.insert(v);
            }
            else
            {
                d=-d;
                lght.erase(d);

                if(m1.count(d))
                {
                    m1.erase(d);
                    sumu-=d;
                }
                else
                {
                    m2.erase(d);

                    ll v=*(m1.begin());
                    sumu-=v;
                    m2.insert(v);
                    m1.erase(v);
                }
            }
        }
        else
        {
            if(d>0)
            {
                m2.insert(d);

                if(!m1.empty() && *m1.begin()<*m2.begin())
                {
                    ll v=*m1.begin();
                    ll u=*m2.begin();

                    sumu+=(u-v);
                    m2.erase(u);
                    m2.insert(v);
                    m1.erase(v);
                    m1.insert(u);
                }
            }
            else
            {
                d=-d;
                if(m2.count(d))
                    m2.erase(d);
                if(m1.count(d))
                {
                    m1.erase(d);

                    sumu-=d;
                    if(!m2.empty())
                    {
                        ll v=*(m2.begin());
                        sumu+=v;
                        m2.erase(v);
                        m1.insert(v);
                    }
                }
            }
        }

//        cout << sumt << ' ' << sumu << '\n';
        ll res=sumt+sumu;
        if(!lght.empty() && *m1.begin()<=*lght.begin())
        {
            res-=*lght.begin();
            if(!m2.empty())
                res+=*(m2.begin());
        }
        db(res)
    }

    return 0;
}
/**
6
1 5
0 10
1 -5
0 5
1 11
0 -10
**/
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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<pip> ops;

ll solve(ll x)
{
    vector<ll> av;
    av.push_back(x);
    ll maa=0;
    for(ll po=0;po<27;po++)
        if(x&(1<<po))
            maa=(1<<po);
    while((av.back()&(-av.back()))!=maa)
    {
        ops.push_back(pip(0,pii(av.back(),av.back())));
        av.push_back(av.back()+av.back());
    }
    ll x1=av.back()^x;
    ll s1=av.back()+x;
    ll s2=x1+x;
    ops.push_back(pip(1,pii(av.back(),x)));
    ops.push_back(pip(0,pii(av.back(),x)));
    ops.push_back(pip(0,pii(x1,x)));
    av.push_back(x1);
    av.push_back(s1);
    av.push_back(s2);
    ll less_important_part=maa+maa-1;
    ll s22=s2-(s2&less_important_part);
    ll s11=s1-(s1&less_important_part);
    ll x11=x1-(x1&less_important_part);
    if(s22==x11)
    {
        ll v1=s2^x1;
        ops.push_back(pip(1,pii(s2,x1)));
        if(v1&maa)
        {
            ll res=x^v1;
            ops.push_back(pip(1,pii(v1,x)));
            return res;
        }
        else
            return v1;
    }
    else
    {
        ll v1=s2^s1;
        ops.push_back(pip(1,pii(s2,s1)));
        if(v1&maa)
        {
            ll res=x^v1;
            ops.push_back(pip(1,pii(v1,x)));
            return res;
        }
        else
            return v1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    while(n!=1)
    {
        int maa=0;
        for(int po=0;po<27;po++)
            if(n&(1<<po))
                maa=(1<<po);
        int ini=n;
        n=solve(n);
        if(!(n&1))
        {
            while(!(n&maa))
            {
                ops.push_back(pip(0,pii(n,n)));
                n<<=1;
            }
            ops.push_back(pip(1,pii(ini,n)));
            n=ini^n;
        }
//        break;
    }
    db(ops.size())
    for(int i=0;i<ops.size();i++)
    {
        if(ops[i].f)
            cout << ops[i].s.f << " ^ " << ops[i].s.s << '\n';
        else
            cout << ops[i].s.f << " + " << ops[i].s.s << '\n';
    }

    return 0;
}
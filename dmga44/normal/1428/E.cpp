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

ll f(ll p,ll x)
{
    ll r1=x/p;
    ll r2=x/p+1;
    ll c2=x%p;
    ll c1=p-(x%p);
    ll sum=c1*r1*r1+c2*r2*r2;
    return sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    priority_queue<pip,vector<pip>,less<pip>> pq;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        ll act=x*x;
        res+=act;
        if(x==1)
        {
            pq.push(pip(0,pii(1,x)));
            continue;
        }
        ll m1=x/2;
        ll m2=x-m1;
        ll nn=m1*m1+m2*m2;
        ll dif=act-nn;
        pq.push(pip(dif,pii(1,x)));
    }
//    db(res)

    for(int i=0;i<k-n;i++)
    {
        pip t=pq.top();
        pq.pop();

//        db(t.f)
        res-=t.f;
        ll div=t.s.f;
        ll x=t.s.s;
//        cout << div << ' ' << x << '\n';
        if(div+1==x)
            continue;
        ll act=f(div+1,x)-f(div+2,x);
        pq.push(pip(act,pii(div+1,x)));
    }
    db(res)

    return 0;
}
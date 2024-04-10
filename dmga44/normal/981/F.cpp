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
typedef double ld;
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
#define mod (ll)(2e9+99)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int n,l;
vector<ll> a;
vector<ll> b;

bool kk(ll x,ll y,ll d)
{
    x%=l;
    y%=l;
    return min(abs(x-y),l-abs(x-y))<=d;
}

int eval(int p,ll x)
{
    for(int i=n;i<2*n;i++)
    {
        int ap=p+i-n;
        if(!kk(a[i],b[ap],x))
        {
            if(a[i]-a[i-1]>b[ap]-b[ap-1])
                return -1;
            else
                return 1;
        }
    }
    return 0;
}

bool ok(ll x)
{
//    db(x)
    vector<int> pos;
    int p=n;
    while(p<2*n && kk(a[n],b[p],x))
    {
        pos.push_back(p);
        p++;
    }
    p=n-1;
    while(p>=0 && kk(a[n],b[p],x))
    {
        pos.push_back(p);
        p--;
    }
//    db("xxx")

    sort(all(pos));

    if(pos.empty())
        return 0;

    ll act=-1;
    for(int p=(1<<18);p;p>>=1)
    {
        if(act+p>=pos.size())
            continue;
        ll v=eval(pos[act+p],x);
        if(!v)
            return 1;
        if(v==-1)
            act+=p;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    a.resize(3*n);
    b.resize(3*n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i]+l;
        a[i+2*n]=a[i]+2*l;
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        b[i+n]=b[i]+l;
        b[i+2*n]=b[i]+2*l;
    }

    sort(all(a));
    sort(all(b));

    ll res=-1;
    for(int po=(1<<29);po;po>>=1)
        if(!ok(res+po))
            res+=po;
    res++;
    db(res)

    return 0;
}
/**
2 4
0 1
2 3
**/
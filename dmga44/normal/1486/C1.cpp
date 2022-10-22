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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int ask(int l,int r)
{
    cout << "? " << l+1 << ' ' << r+1 << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    int p=ask(0,n-1);

    int ty=0;
    if(p==1)
        ty=1;
    else if(p!=n)
    {
        if(ask(0,p-1)!=p)
            ty=1;
    }
//    db("xxx")

    int res=-1;
    for(int po=(1<<16);po;po>>=1)
    {
        if(!ty)
        {
            int l=res+po;
            if(l>=p-1)
                continue;
            if(ask(l,p-1)==p)
                res+=po;
        }
        else
        {
            int r=n-(res+po)-1;
            if(r<=p-1)
                continue;
            if(ask(p-1,r)==p)
                res+=po;
        }
    }
    if(ty)
        res=n-res-1;
    res++;
    cout << "! " << res << '\n';
    cout.flush();

    return 0;
}
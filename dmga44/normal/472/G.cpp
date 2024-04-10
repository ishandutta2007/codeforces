#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ull ba[MAXN/64+5];
ull bb[MAXN/64+5];

ull mask(int l,int r)
{
    return (((((ull)(-1))>>(64-r-1))>>l)<<l);
}

ull apply(ull x,int min,int p)
{
    return ((x>>min)<<p);
}

ull shifts(ull x,int l,int r,int p)
{
    // cout << "\nshift:\n";
    // cout << x << ' ' << l << ' ' << r << ' ' << p << '\n';
    // cout << apply(x&mask(l,r),l,p) << '\n';
    // cout << mask(l,r) << '\n';
    return apply(x&mask(l,r),l,p);
}

void mids(ull& v1,ull& v2,ull v,int p)
{
    // cout << v1 << ' ' << v2 << ' ' << v << ' ' << p << '\n';
    if(p>=64)
    {
        v2^=shifts(v,0,63,p-64);
        // cout << shifts(v,0,63,p-64) << '\n';
        // cout << v1 << ' ' << v2 << ' ' << v << ' ' << p << '\n';
        return ;
    }
    v1^=shifts(v,0,63-p,p);
    v2^=shifts(v,63-p+1,63,0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    int la=a.size();
    int lb=b.size();
    ull bit=1;
    for(int i=0;i<la;i++)
    {
        ba[i/64]|=(a[i]=='1')*bit;
        bit<<=1;
        if(bit==0)
            bit=1;
    }
    bit=1;
    for(int i=0;i<lb;i++)
    {
        // cerr << bit << '\n';
        bb[i/64]|=(b[i]=='1')*bit;
        bit<<=1;
        if(bit==0)
            bit=1;
    }
    ull x=1ll<<62;
    // db(apply(x,1,2))
    // db(apply(x,1,3))
    // db(apply(x,1,4))
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int p1,p2,len;
        cin >> p1 >> p2 >> len;
        vector<ull> act((len-1)/64+1);

        int l1=p1,r1=p1+len-1;
        if(l1/64==r1/64)
            act[0]^=shifts(ba[l1/64],l1%64,r1%64,0);
        else
        {
            act[0]^=shifts(ba[l1/64],l1%64,63,0);
            for(int m=(l1/64)+1;m<r1/64;m++)
            {
                mids(act[m-((l1/64)+1)],act[m-(l1/64)],ba[m],64-(l1%64));
            }
            if(len>64)
                mids(act[(len-1)/64-1],act[(len-1)/64],shifts(ba[r1/64],0,r1%64,0),64+((len-1)%64)-(r1%64));
            else
            {
                ull vfb;
                mids(act[(len-1)/64],vfb,shifts(ba[r1/64],0,r1%64,0),((len-1)%64)-(r1%64));
            }
        }
        // cout << act[0] << '\n';
        // cout << act[1] << '\n';

        int l2=p2,r2=p2+len-1;
        if(l2/64==r2/64)
            act[0]^=shifts(bb[l2/64],l2%64,r2%64,0);
        else
        {
            act[0]^=shifts(bb[l2/64],l2%64,63,0);
            for(int m=(l2/64)+1;m<r2/64;m++)
            {
                mids(act[m-((l2/64)+1)],act[m-(l2/64)],bb[m],64-(l2%64));
            }
            if(len>64)
                mids(act[(len-1)/64-1],act[(len-1)/64],shifts(bb[r2/64],0,r2%64,0),64+((len-1)%64)-(r2%64));
            else
            {
                ull vfb;
                mids(act[(len-1)/64],vfb,shifts(bb[r2/64],0,r2%64,0),((len-1)%64)-(r2%64));
            }
        }
        // cout << act[0] << '\n';
        // cout << act[1] << '\n';
        ll ans=0;
        for(auto y : act)
            ans+=__builtin_popcountll(y);
        cout << ans << '\n';
    }

    return 0;   
}
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
#define MAXN (ll)(2e2+5)

vector<int> solve(vector<int> ps)
{
    int n=ps.size()+1;
    vector<int> res(n);
    vector<vector<int> > ds;
    for(int i=0;i<n;i++)
        ds.push_back({i});
    for(int i=0;i<n-1;i++)
    {
        int p=ps[i];
        int i0=-1;
        int i1=-1;
        for(int j=0;j<n;j++)
            for(auto y : ds[j])
                if(y==p)
                    i0=j;
        for(int j=0;j<n;j++)
            for(auto y : ds[j])
                if(y==p+1)
                    i1=j;
        for(auto y : ds[i0])
            ds[i1].push_back(y);
        ds[i0]={};

        for(auto y : ds[i1])
            res[y]^=1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    int fac[13];
//    fac[0]=1;
//    for(int i=1;i<13;i++)
//        fac[i]=fac[i-1]*i;
//
//    int n;
//    cin >> n;
//    vector<pii> a(n+1);
//    vector<int> vs;
//    int cb=0;
//    ll ac=-oo;
//    for(int i=0;i<n+1;i++)
//    {
//        cin >> a[i].f;
//        a[i].s=i;
//        if(a[i].f>=0)
//            cb++;
//    }
//    vector<int> fs(n+2);
//    vector<bool> mkk(1<<(n+1));
//    for(int i=0;i<fac[n];i++)
//    {
////        db(i)
//        int v=i;
//        vector<int> ps;
//        vector<bool> mk(n);
//        for(int j=0;j<n;j++)
//        {
//            int x=v/fac[n-j-1];
//            v%=fac[n-j-1];
//            int a=-1;
//            for(int k=0;k<n;k++)
//            {
//                if(mk[k])
//                    continue;
//                if(x==0)
//                {
//                    a=k;
//                    break;
//                }
//                x--;
//            }
//            ps.push_back(a);
//            mk[a]=1;
//        }
//
////        db("")
////        for(auto y : ps)
////            cout << y << ' ';
////        cout << '\n';
//        vector<int> vv=solve(ps);
//        int k=0;
//        ll sum=0;
//        for(int i=0;i<n+1;i++)
//        {
//            if(!vv[i])
//                sum+=a[i].first;
//            else
//                sum-=a[i].f;
////            cout << vv[i] << ' ';
//            k|=(vv[i]*(1<<i));
//        }
//        if(sum>ac)
//        {
//            ac=sum;
//            vs=vv;
//        }
//
//        if(!mkk[k])
//            fs[__builtin_popcount(k)]++;
//        mkk[k]=1;
////        cout << '\n';
//    }
//    db(ac)
//    for(auto y : vs)
//        cout << y << ' ';
//    cout << '\n';
//    for(int i=0;i<=n+1;i++)
//        cout << fs[i] << ' ';
//    cout << '\n';

    int n;
    cin >> n;
    int r=(2-(n%3));
    vector<pii> a(n);
    int cb=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].f;
        a[i].s=i;
        if(a[i].f>=0)
            cb++;
    }

    sort(allr(a));
    if(n<3)
    {
        if(n==1)
            db(a[0].f)
        else
            db(-(a[0].f+a[1].f))
        return 0;
    }

//    for(int i=0;i<n;i++)
//        cout << i << ' ' << a[i].f << ' ' << a[i].s << '\n';

    int c1=max(cb-(((cb%3)-r+3)%3),r);
    int c2=c1;
    int c3=c1;
    if(c1-3>=0)
        c3=c1-3;
    if(c1+3<=n)
        c2=c1+3;
    ll res=-oo;
//    cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
    if(c1>=0)
    {
        ll sum=0;
        for(int i=0;i<c1;i++)
            sum+=a[i].f;
        for(int i=c1;i<n;i++)
            sum-=a[i].f;
        vector<bool> mkk(n);
        for(int i=c1;i<n;i++)
            mkk[a[i].s]=1;
        bool kk=1;
        for(int i=1;i<n;i+=2)
            kk=(kk&(mkk[i]));
//        db(sum)
//        db(kk)
        if((n&1) && c1==(n/2+1) && kk)
        {
            sum-=2*a[c1-1].f;
            sum+=2*a[c1].f;
        }
//        db(sum)
        res=sum;
    }
    {
        ll sum=0;
        for(int i=0;i<c2;i++)
            sum+=a[i].f;
        for(int i=c2;i<n;i++)
            sum-=a[i].f;
        vector<bool> mkk(n);
        for(int i=c2;i<n;i++)
            mkk[a[i].s]=1;
        bool kk=1;
        for(int i=1;i<n;i+=2)
            kk=(kk&(mkk[i]));
        if((n&1) && c2==(n/2+1) && kk)
        {
            sum-=2*a[c2-1].f;
            sum+=2*a[c2].f;
        }
//        db(sum)
        res=max(sum,res);
    }
    {
        ll sum=0;
        for(int i=0;i<c3;i++)
            sum+=a[i].f;
        for(int i=c3;i<n;i++)
            sum-=a[i].f;
        vector<bool> mkk(n);
        for(int i=c3;i<n;i++)
            mkk[a[i].s]=1;
        bool kk=1;
        for(int i=1;i<n;i+=2)
            kk=(kk&(mkk[i]));
        if((n&1) && c3==(n/2+1) && kk)
        {
            sum-=2*a[c3-1].f;
            sum+=2*a[c3].f;
        }
//        db(sum)
        res=max(sum,res);
    }
    db(res)

    return 0;
}
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX
//
//#include <bits/stdc++.h>
//#define db(x) cout << (x) << '\n';
//#define all(v) (v).begin(),(v).end()
//#define allr(v) (v).rbegin(),(v).rend()
//#define f first
//#define s second
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//typedef pair<ll,ll> pii;
//typedef pair<ld,ll> pdi;
//typedef pair<ld,ld> pdd;
//typedef pair<ld,pdd> pdp;
//typedef pair<string,ll> psi;
//typedef pair<ll,string> pls;
//typedef pair<string,string> pss;
//typedef pair<ll,pii> pip;
//typedef pair<pii,pii> ppp;
//typedef complex<ll> point;
//typedef vector<point> polygon;
//typedef pair<point,int> ppi;
//#define prec(n) cout.precision(n); cout<<fixed
//const ll mod=(1e9+7);
//const ld eps=(1e-9);
//const ll oo=(ll)(1e9+5);
//#define pi acos(-1)
//#define MAXN (ll)(1e5+5)
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int n;
//    cin >> n;
//    vector<int> xs;
//    vector<int> ys;
//    vector<pii> ps;
//    for(int i=0;i<n;i++)
//    {
//        int x,y;
//        cin >> x >> y;
//        xs.push_back(x);
//        ys.push_back(y);
//        ps.push_back(pii(x,y));
//    }
//
//    ll d;
//    cin >> d;
//    ll vs[4];
//    for(int i=0;i<n;i++)
//    {
//        int x=ps[i].f;
//        int y=ps[i].s;
//        if(i==0)
//        {
//            vs[0]=x+y+d;
//            vs[1]=x-y+d;
//            vs[2]=-x+y-d;
//            vs[3]=-x-y-d;
//        }
//        else
//        {
//            vs[0]=min(x+y+d,vs[0]);
//            vs[1]=min(x-y+d,vs[1]);
//            vs[2]=max(-x+y-d,vs[2]);
//            vs[3]=max(-x-y-d,vs[3]);
//        }
//    }
//
//    if(vs[0]<vs[3] || vs[1]<vs[2])
//    {
//        db("impossible")
//        return 0;
//    }
//
//    sort(all(xs));
//    sort(all(ys));
//
//    vector<pip> dx;
//    vector<pip> dy;
//    pii bx,by;
//    dx.push_back(pip(-n,pii(-3e9,xs[0])));
//    for(int i=0;i+1<n;i++)
//    {
//        if(xs[i]!=xs[i+1])
//            dx.push_back(pip(2*(i+1)-n,pii(xs[i],xs[i+1])));
//        if(i==)
//    }
//    dx.push_back(pip(n,pii(xs[n-1],3e9)));
//
//    dy.push_back(pip(-n,pii(-3e9,ys[0])));
//    for(int i=0;i+1<n;i++)
//    {
//        if(ys[i]!=ys[i+1])
//            dy.push_back(pip(2*(i+1)-n,pii(ys[i],ys[i+1])));
//
//    }
//    dy.push_back(pip(n,pii(ys[n-1],3e9)));
//
//    return 0;
//}
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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e9+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll rsq[MAXN][18];
ll rxq[MAXN][18];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for(int i=0;i<n;i++)
        rsq[a[i]][0]++;

    for(int j=1;(1<<j)<=m;j++)
        for(int i=0;i+(1<<j)<=m;i++)
        {
            rsq[i][j]+=rsq[i][j-1]+rsq[i+(1<<(j-1))][j-1];
            rxq[i][j]=rxq[i+(1<<(j-1))][j-1]^rxq[i][j-1];
            if(rsq[i+(1<<(j-1))][j-1]&1)
                rxq[i][j]^=(1<<(j-1));
        }

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        ll d=r-l+1;
        vector<int> sz;
        for(int i=0;i<18;i++)
            if(d&(1<<i))
                sz.push_back(i);

        ll ac=0,pos=r,ans=0;
        for(auto x : sz)
        {
            ans^=rxq[pos-(1<<x)+1][x];
            if(ac&1)
                ans^=(1<<x);
            ac+=rsq[pos-(1<<x)+1][x];
            pos-=(1<<x);
//            cout << x << ' ' << ans << '\n';
        }
//        db("")
        cout << "AB"[ans==0];
    }
    cout << '\n';

    return 0;
}
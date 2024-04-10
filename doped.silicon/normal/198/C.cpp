// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

// #define INF 1000000000000000000ll
#define MOD  998244353
// #define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ll x,y,v;
ll x2,y2,v1;
ld R;
ll ra;
ld om;
ld th;
pair<ld,ld> find(ld t)
{
    return mp(R*cos(th+t*om),R*sin(th+t*om));
} 
f80 INF=1e100;
f80 EPS=1e-7;
const f80 PI=acosl(-1);
struct PT {
f80 x, y;
PT() {}
PT(f80 x, f80 y) :   x(x), y(y) {}
PT(const PT &p) :  x(p.x), y(p.y) {}
PT operator +(const PT &p) const { return PT(x+p.x,y+p.y);}
PT operator -(const PT &p) const { return PT(x-p.x,y-p.y);}
PT operator *(f80 c) const { return PT(x*c,y*c);}
PT operator /(f80 c) const { return PT(x/c,y/c);}
};
f80 dot(PT p, PT q) {
return p.x*q.x+p.y*q.y;
}
f80 dist2(PT p, PT q) {
return dot(p-q,p-q);
}
f80 dist(PT p, PT q) {
return sqrtl(dist2(p,q));
}
f80 cross(PT p, PT q) {
return p.x*q.y-p.y*q.x;
}
f80 abs2(PT a) {
return a.x*a.x+a.y*a.y;
}
f80 abs(PT a) {
return sqrtl(abs2(a));
}
ostream& operator<<(ostream &os, const PT &p) {
return os<<"("<<p.x<<","<<p.y<<")";
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p) {
return PT(-p.y,p.x);
}
PT RotateCW90(PT p) {
return PT(p.y,-p.x);
}
PT RotateCCW(PT p, f80 t) {
return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
return a+(b-a)*dot(c-a,b-a)/dot(b-a,b-a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
f80 r=dot(b-a,b-a);
if(fabs(r)<EPS)
  return a;
r=dot(c-a,b-a)/r;
if(r<0)
  return a;
if(r>1)
  return b;
return a+(b-a)*r;
}
// compute distance from c to segment between a and b
f80 DistancePointSegment(PT a, PT b, PT c) {
return sqrtl(dist2(c,ProjectPointSegment(a,b,c)));
}

void solve() 
{
    cin>>x>>y>>v;
    cin>>x2>>y2>>v1;
    cin>>ra;
    ld l=0,r=10000000000000;
    R=sqrt(x*x+y*y);
    om=v/R;
    th=atan2(y,x);
    PT a,b,c;
    a.x=x2;
    a.y=y2;
    c.x=0;
    c.y=0;
    ld th1=atan2(y2,x2);
    rep(i,100)
    {
        ld m=(l+r)/2.0;
        auto zz=find(m);
        ld xx=zz.ff;
        ld yy=zz.ss;
        b.x=xx;
        b.y=yy;
        ld cx=DistancePointSegment(a,b,c);
        ld t=0;
        if(m>2.8&&m<=2.9)
        {
            trace(cx);
        }
        if(cx<ra)
        {
            ld ax=sqrt(xx*xx+yy*yy-ra*ra);
            ld bx=sqrt(x2*x2+y2*y2-ra*ra);
            t=(ax+bx)/v1;
            ld tx1=atan2(ax,ra);
            ld tx2=atan2(bx,ra);
            ld tt=atan2(yy,xx);
            ld zx=abs(th1-tt); 
            // trace(zx);
            ld tx3=min(zx,2*PI-zx);
            // trace(tx1);
            // trace(tx2);
            tx3-=tx1;
            tx3-=tx2;
            tx3*=ra;
            t=(t+tx3/v1);
        }
        else
        {
            t=dist(a,b)/v1;
        }
        if(t<m)
        {
            r=m;
        }
        else
        {
            l=m;
        }
        // trace(l,r);
    }
    cout<<l<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}
// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ritick
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

// #define INF 100000000000000000
#define MOD 1000000007
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

#ifdef ritick
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
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng32)
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }

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
// compute distance between point (x,y,z) and plane ax+by+cz=d
f80 DistancePointPlane(f80 x, f80 y, f80 z, f80 a, f80 b, f80
  c, f80 d)
{ return fabs(a*x+b*y+c*z-d)/sqrtl(a*a+b*b+c*c);}
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
return fabs(cross(b-a,c-d))<EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
return LinesParallel(a,b,c,d)&&fabs(cross(a-b,a-c))<EPS&&fabs(cross(c-d,c-a))<EPS;

}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
if(LinesCollinear(a,b,c,d)) {
  if(dist2(a,c)<EPS||dist2(a,d)<EPS||dist2(b,c)<EPS||dist2(b,d)<EPS)
    return 1;
  if(dot(c-a,c-b)>0&&dot(d-a,d-b)>0&&dot(c-b,d-b)>0)
    return 0;
  return 1;
}
if(cross(d-a,b-a)*cross(c-a,b-a)>0)
  return 0;
if(cross(a-c,d-c)*cross(b-c,d-c)>0)
  return 0;
return 1;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
b=b-a;
d=c-d;
c=c-a;
assert(dot(b,b)>EPS&&dot(d,d)>EPS);
return a+b*cross(c,d)/cross(b,d);
}

ll find(pair<PT,PT>a)
{
    ll x1=abs(a.ss.y-a.ff.y);
    ll y1=abs(a.ff.x-a.ss.x);
    return __gcd(y1,x1)+1;
}
void solve() 
{   
   ll n;
   cin>>n;
   vector<pair<PT,PT>>v;
   ll ans=0;
   rep(i,n)
   {
        PT a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        v.pb(mp(a,b));
        ans+=find(v[i]);
   }
   trace(ans);
   map<pair<ll,ll>,ll>m;
   rep(i,n)
   {
        for(ll j=i+1;j<n;j++)
        {
            if(SegmentsIntersect(v[i].ff,v[i].ss,v[j].ff,v[j].ss))
            {
                PT bt=ComputeLineIntersection(v[i].ff,v[i].ss,v[j].ff,v[j].ss);
                ll x=(ll)bt.x;
                ll y=(ll)bt.y;
                // trace(bt.x,x);
                // trace(bt.y,y);
                if(x==bt.x&&y==bt.y)
                {
                    // trace(i,j);
                    m[mp(x,y)]++;
                }
                // cout<<endl;
            }        
        }
   }
   for(auto z:m)
   {
        for(ll i=2;i<=1005;i++)
        {
            if(i*(i-1)/2==z.ss)
            {
                ans-=(i-1);
                break;
            }
        }
   }
   cout<<ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
    #ifdef ritick
        cin.exceptions(cin.failbit);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}
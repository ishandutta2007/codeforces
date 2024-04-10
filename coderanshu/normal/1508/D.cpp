#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

template<typename T = long long>
struct Point
{
    T x,y;
    int id;
    Point() : x(0),y(0) {}
    Point(T x_,T y_): x(x_),y(y_) {}
    friend Point operator-(const Point &a, const Point &b) { return Point(a.x-b.x,a.y-b.y); }
    friend Point operator+(const Point &a, const Point &b) { return Point(a.x+b.x,a.y+b.y); }
    friend ostream& operator << (ostream &stream, const Point &P) { return stream<<"("<<P.x<<","<<P.y<<")"; }
    long long abs() { return x*x + y*y; }
};
template<typename T>
T dot(const Point<T> &a,const Point<T> &b)
{
    return a.x*b.x+a.y*b.y;
}
template<typename T>
T cross(const Point<T> &a,const Point<T> &b)
{
    return a.x*b.y-b.x*a.y;
}
using Pt = Point<ll> ;
struct AngCmp
{
    // centred at origin and anticlockwise relative to V;
    Pt origin,V;
    AngCmp(Pt a,Pt b): origin(a),V(b) {}

    bool operator() (const Pt &a,const Pt &b) const
    {
        Pt A = a-origin;
        Pt B = b-origin;

        bool x = cross(V,A)>=0;
        bool y = cross(V,B)>=0;
        if(x^y)
            return x;
        ll u = cross(A,B);
        if(u != 0)
            return u > 0;
        ll ux = dot(A,B);
        ll vx = dot(A,V);
        if(ux < 0)
            return vx > 0;
        // change here for same polar angle
        return A.abs()>B.abs();
    }
};

// AngCmp cmp(Pt(0,0),Pt(1,0)) <-- Like this

const int N = 2005;
int par[N],sz[N];
int parent(int i)
{
    return par[i] == i?i:parent(par[i]);
}
int comp;
bool merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x == y)
        return false;
    if(sz[x] > sz[y])
        swap(x,y);
    par[x] = y;
    sz[y] += sz[x];
    --comp;
    return true;
}   

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> p(n+1);
    comp = n;
    for(int i=1;i<=n;++i)
        par[i] = i,sz[i] = 1;
    vector<Pt> pts;
    for(int i=1;i<=n;++i)
    {
        Pt x;
        cin>>x.x>>x.y>>p[i];
        x.id = i;
        merge(i,p[i]);
        if(i == p[i])
            continue;
        pts.push_back(x);
    }
    if(pts.empty())
    {
        cout<<"0\n";return 0;
    }
    Pt a = pts.back();
    pts.pop_back();
    AngCmp cmp(a,Pt(1,0));
    sort(all(pts),cmp);
    auto make = [&](int i,int j)
    {
        swap(p[i],p[j]);
    };
    vector<pii> ans;
    for(int i=0;i<sz(pts);++i)
    {
        if(cross(pts[i]-a,pts[(i+1)%sz(pts)]-a) >= 0 && merge(pts[i].id,pts[(i+1)%sz(pts)].id))
        {
            ans.push_back({pts[i].id,pts[(i+1)%sz(pts)].id});
            make(pts[i].id,pts[(i+1)%sz(pts)].id);
        }
    }
    int cur = a.id;
    while(p[cur] != cur)
    {
        ans.push_back({cur,p[cur]});
        make(cur,p[cur]);
    }
    // assert(comp == 1);
    cout<<sz(ans)<<"\n";
    for(auto &[j,k]:ans)
        cout<<j<<" "<<k<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}
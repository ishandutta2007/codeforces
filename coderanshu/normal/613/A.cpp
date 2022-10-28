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

struct Point {
    long long x,y;
    Point() {}
    Point(long long x_,long long y_) {
        x = x_;
        y = y_;
    }
    friend istream& operator>>(istream &i,Point &p) {
        return i >> p.x >> p.y;
    }
    double dis(Point &p) {
        return sqrt(pow(p.x-x,2) + pow(p.y-y,2));
    }
    long long cross(Point r) {
        return x * r.y - y * r.x;
    }
};

Point operator-(Point &l,Point &r){
    return Point(l.x-r.x,l.y-r.y);
}
int _runtimeTerror_()
{
    int n;
    Point P;
    cin>>n>>P;
    vector<Point> p(n);
    for(int i=0;i<n;++i)
        cin>>p[i];
    double max = 0,min = 1e9;
    for(int i=0;i<n;++i)
    {
        amax(max,P.dis(p[i]));
        amin(min,P.dis(p[i]));
        Point d = p[i] - p[(i+1)%n];
        swap(d.x,d.y);
        d.x *= -1;
        if(((p[i]-P).cross(d)>0?1:-1) * ((p[(i+1)%n]-P).cross(d)>0?1:-1) < 0)
            amin(min,abs((p[i]-P).cross(p[(i+1)%n]-p[i])/p[i].dis(p[(i+1)%n])));
    }
    cout<<fixed<<setprecision(20);
    cout<<acos(-1)*(max * max - min * min);
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
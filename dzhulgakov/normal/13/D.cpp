#define _CRT_SECURE_NO_WARNINGS
#include <bitset>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

template <typename T> struct Point {
    T x,y;
    Point(T _x=0,T _y=0) : x(_x),y(_y) {}
    void read();
    void swap() { swap(x,y); }
    double len() const;
    Point<double> asDouble() { return Point<double>(x,y); }
    Point<T> norm() const;
    Point<T> ort() const { return Point<T>(y,-x); }
};
template<> void Point<int>::read() { scanf("%d%d",&x,&y); }
template<> void Point<LL>::read() { scanf("%lld%lld",&x,&y); }
template<> void Point<double>::read() { scanf("%lf%lf",&x,&y); }
template <typename T> Point<T> operator- (const Point<T> &a) { return Point<T>(-a.x,-a.y); }
template <typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y); }
template <typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y); }
template <typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator* (const Point<T> &b, const T a) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator/ (const Point<T> &b, const T a) { return Point<T>(b.x/a,b.y/a); }
template <typename T> LL operator* (const Point<T> &a, const Point<T> &b) { return a.x*(LL)b.x+a.y*(LL)b.y; }
template <typename T> LL operator^ (const Point<T> &a, const Point<T> &b) { return a.x*(LL)b.y-a.y*(LL)b.x; }
template <typename T> double Point<T>::len() const { return sqrt((double)((*this)*(*this))); }
template <typename T> Point<T> Point<T>::norm() const { return (*this)/len(); }
template <typename T> bool operator< (const Point<T> &a, const Point<T> &b) { return a.x<b.x || a.x==b.x && a.y<b.y; }
bool operator== (const Point<LL> &a, const Point<LL> &b) { return a.x==b.x && a.y==b.y; }
int sign(int x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(double x) { if (fabs(x)<eps) return 0; if (x>0) return +1; else return -1; }
template<typename T> T sqr(T x) { return x*x; }
typedef Point<double> DPnt;
typedef Point<int> IPnt;
const DPnt INFDPnt(1.0e30,1.0e30);

#define N 512
#define BL 32
typedef bitset<N> BS;
int n,m;
IPnt a[N],b[N];
int d[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    REP(i,n)
        a[i].read();
    sort(a,a+n);
    REP(j,m)
        b[j].read();
    CLEAR(d);
    REP(i,n) REP(j,i) if (a[i].x!=a[j].x)
    {
        REP(ii,m)
            if (a[j].x <= b[ii].x && b[ii].x < a[i].x && ((b[ii]-a[j])^(a[i]-a[j]))<0)
            {
                d[i][j]++;
                d[j][i]--;
            }
    }
    int res=0;
    REP(i1,n) REP(i2,i1) REP(i3,i2)
    {
        int k = d[i1][i2]+d[i2][i3]+d[i3][i1];
        if (k==0)
            res++;
    }
    printf("%d\n",res);
    return 0;
}
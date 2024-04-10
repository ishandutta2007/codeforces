// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define real long double //albo long double
const real eps=1e-9;
inline bool iszero(real x){return x<=eps && x>=-eps;}
struct pt {
    real x,y;
    pt(real xx=0,real yy=0):x(xx),y(yy){}
    bool operator==(const pt &a){return iszero(a.x-x) && iszero(a.y-y);}
};
bool operator<(const pt &a, const pt &b) {
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
ostream& operator<<(ostream &s,pt p) {return s<<"("<<p.x<<","<<p.y<<")";}

pt operator+(pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(pt a,real r){return pt(a.x*r,a.y*r);}
real vec(pt a,pt b){return a.x*b.y-a.y*b.x;}
real det(pt a,pt b,pt c){return vec(b-a,c-a);}

pt operator*(pt a,pt b){return pt(a.x*b.x-a.y*b.y,b.x*a.y+b.y*a.x);}
real sqabs(pt a){return a.x*a.x+a.y*a.y;}
pt operator/(pt a,pt b) {return (a*pt(b.x,-b.y))/sqabs(b);}

real abs(pt a){return sqrt(a.x*a.x+a.y*a.y);}
real dist(pt a,pt b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(pt a,pt b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

real arg(pt a){return atan2(a.y,a.x);}//z przedzialu [-pi,pi]
real skal(pt a,pt b){return a.x*b.x+a.y*b.y;}

// odleglosc A od prostej BC
real dist(pt a,pt b,pt c){return abs(det(b,c,a))/dist(b,c);}
//dlugosc (ze znakiem) rzutu A na prosta B
real dlrzut(pt a,pt b){return skal(a,b)/abs(b);}

pt rzut(pt a,pt b,pt c) { //rzut punktu A na prosta BC
    pt d=c-b;
    return b+d*(skal(a-b,d)/sqabs(d));
}
real pole(vector<pt> &po) {
    real pole=0.0;
    int dl=SZ(po);
    FOR(i,dl) pole+=po[i].x*po[(i+1)%dl].y-po[(i+1)%dl].x*po[i].y;
    return fabs(pole)/2.0;
}


int main () {
    wez3(a1,a2,a3)
    wez3(a4,a5,a6)
    vector<pt> poly;
    pt p(0,0);
    poly.pb(p);
    p = p + a1 * pt(1,0);
    poly.pb(p);
    const real sq3 = sqrt(3.0L);
    p = p + a2 * pt(0.5, sq3/2);
    poly.pb(p);
    p = p + a3 * pt(-0.5, sq3/2);
    poly.pb(p);
    p = p + a4 * pt(-1, 0);
    poly.pb(p);
    p = p + a5 * pt(-0.5, -sq3/2);
    poly.pb(p);
    p = p + a6 * pt(0.5, -sq3/2);
    //DBG(p == pt(0,0));
    cout << (long long)(round(pole(poly) / (sq3 / 4)));
}
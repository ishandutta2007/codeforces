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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define real double //albo long double
const real eps=1e-9;
inline bool iszero(real x){return x<=eps && x>=-eps;}
struct pt {
    real x,y;
    pt(real xx=0,real yy=0):x(xx),y(yy){}
    bool operator==(pt &a){return iszero(a.x-x) && iszero(a.y-y);}
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

int line_cross(pt a, pt b,pt c,pt d,pt& wyn) { // 0 brak, 1 przec, 2 pokrywaja
    real pczw=vec(b-a,c-d);
    if (iszero(pczw)) {
        if (iszero(det(a,b,c))) return 2;
        else return 0;
    }
    real ptr=vec(b-a,c-a);
    wyn=c+(d-c)*(ptr/pczw);
    return 1;
}

real pole(vector<pt> &po) {
    real pole=0.0;
    int dl=SZ(po);
    FOR(i,dl) pole+=po[i].x*po[(i+1)%dl].y-po[(i+1)%dl].x*po[i].y;
    return fabs(pole)/2.0;
}

//przeciecie wypuklego wielokata p i polplaszczyzny {x:det(a,b,x)<=0}
vector<pt> poly_halfplane(vector<pt> p,pt a,pt b) { //zlozonosc O(|p|)
    int n=SZ(p);
    if (!n) return p;
    p.pb(p[0]);
    vector<pt> wyn;
    vector<bool> side(n+1);
    pt cross;
    FOR(i,n+1) side[i]=(det(a,b,p[i])>=-eps);
    FOR(i,n) {
        if (side[i]==1) {
            wyn.pb(p[i]);
            if (side[i+1]==0 && line_cross(p[i],p[i+1],a,b,cross)==1
                             && !(cross==p[i])) wyn.pb(cross);
        }
        if (side[i]==0 && side[i+1]==1 && line_cross(p[i],p[i+1],a,b,cross)==1
                       && !(cross==p[i+1])) wyn.pb(cross);
    }
    return wyn;
}

#define N 306
real res[N], y[N][N];

int main () {
   wez2(n,k)
   FOR(i,n) {
      REP(j,0,k) {
         wez(x)
         y[i][j] = x;
      }
   }
   FOR(j,k) {
      vector<pt> p;
      p.pb(pt(j+1,1001));
      p.pb(pt(j,  1001));
      p.pb(pt(j,  0));
      p.pb(pt(j+1,0));
      real area = 1001;
      FOR(i,n) {
         pt a = pt(j, y[i][j]), b = pt(j+1, y[i][j+1]);
         p = poly_halfplane(p, a, b);
         real newarea = pole(p);
         res[i] += area - newarea;
         area = newarea;
      }
   }
   FOR(i,n) printf("%.14lf\n", res[i]);
}
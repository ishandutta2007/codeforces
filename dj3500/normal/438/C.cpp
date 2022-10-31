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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
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

bool przecinanie(pt a,pt b,pt c,pt d) { //czy przeciecie AB CD niepuste
    real d1=vec(b-a,c-a),d2=vec(b-a,d-a);
    if ((d1>eps && d2>eps) || (d1<-eps && d2<-eps)) return 0;
    if (iszero(d1) && iszero(d2)) {
        if (iszero(a.x-b.x) && iszero(c.x-d.x))
            a=a*pt(0,1);b=b*pt(0,1);c=c*pt(0,1);d=d*pt(0,1);
        if (a.x>b.x) swap(a,b);
        if (c.x>d.x) swap(c,d);
        if (a.x<c.x+eps && c.x<b.x+eps) return 1; 
        if (a.x<d.x+eps && d.x<b.x+eps) return 1; 
        if (c.x<a.x+eps && a.x<d.x+eps) return 1;
        return 0; 
    }
    d1=vec(d-c,a-c),d2=vec(d-c,b-c);
    if ((d1>eps && d2>eps) || (d1<-eps && d2<-eps)) return 0;
    return 1;
}


bool insegment(pt a,pt b,pt c) { //A nalezy do BC
    if (iszero(det(a,b,c)))
        if (min(b.x,c.x)-eps<=a.x && a.x-eps<=max(b.x,c.x))
            if (min(b.y,c.y)-eps<=a.y && a.y-eps<=max(b.y,c.y)) return 1;
    return 0;
}


//przeciecie w dokl 1 punkcie ktory nie jest koncem
bool przecinanie_wl(pt a,pt b,pt c,pt d) {
    real d1=vec(b-a,c-a),d2=vec(b-a,d-a);
    if (!(d1>eps && d2<-eps) && !(d1<-eps && d2>eps)) return 0;
    d1=vec(d-c,a-c),d2=vec(d-c,b-c);
    if (!(d1>eps && d2<-eps) && !(d1<-eps && d2>eps)) return 0;
    return 1;
}

//czy nalezy do wnetrza, jesli jest na brzegu to undefined behaviour
bool inpoly(pt a, vector<pt> &pol) {
   //DBG(a)
   //return 1;
    pt b(3e8+500.0,4e6+77777.0);
    int pr=0;
    FOR(i,SZ(pol)) pr+=przecinanie_wl(a,b,pol[i],pol[(i+1)%SZ(pol)]);
    return pr%2;
}
bool onborder(pt a, vector<pt> &pol) { //czy nalezy do brzegu
    FOR(i,SZ(pol)) if (insegment(a,pol[i],pol[(i+1)%SZ(pol)])) return 1;
    return 0;
}

vector<pt> poly;
#define N 505
ll dp[N][N];
bool ok[N][N];
const int mod = 1000000007;

int main () {
   wez(n)
   FOR(i,n) {
      wez(xi)
      wez(yi)
      poly.pb(pt(xi,yi));
   }
   
   FOR(p,n) dp[p][(p+1) % n] = 1;
   REP(d,2,n-1) {
      // wyznacz dp
      FOR(p,n) {
         int q = (p + d) % n;
         dp[p][q] = 0;
         
         // 1
         pt srodek = poly[p] + (poly[q] - poly[p]) * 0.46579841564;
         if (p == 1 && q == 4) {
            //DBG(srodek)
         }
         if ((!inpoly(srodek, poly)) && (!onborder(srodek,poly))) {
            /*DBG(mp(p,q))
            DBG(srodek)
            DBG(inpoly(srodek,poly))
            DBG(onborder(srodek, poly))
            cerr<<setprecision(10)<<fixed;DBG(det(srodek,poly[0],poly[n-1]))*/
            continue;
         }
         // 2
         bool bad = 0;
         /*FOR(k,n) if ((k+1)%n != p && k != p &&(k+1)%n != q && k != q) {
            if (przecinanie(poly[p], poly[q], poly[k], poly[(k+1)%n])) bad = 1;
         }*/
         FOR(k,n) if (!(k == p && (k+1)%n == q) && !(k == q && (k+1)%n == p)) {
            if (przecinanie_wl(poly[p], poly[q], poly[k], poly[(k+1) % n])) bad = 1;
         }
         FOR(k,n) if (k != p && k != q) {
            if (insegment(poly[k], poly[p], poly[q])) bad = 1;
         }
         if (bad) {
            //DBG(mp(p,q))
            continue;
         }
         //if (!ok[p][q]) continue;
         for (int r = (p+1) % n; r != q; r = (r+1) % n) {
            dp[p][q] += dp[p][r] * dp[r][q] % mod;
         }
         dp[p][q] %= mod;
      }
   }
   int res = dp[0][n-1];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
   //DBG(dp[1][0])
}
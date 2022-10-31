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

typedef long long real;
bool iszero (ll x) { return x == 0; }
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
real sqdist(pt a,pt b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

pt p[100100];

int main () {
   wez(n);
   FORI(i,n) {
      wez2(x,y);
      p[i] = pt(x,y);
   }
   pair<real,int> mini(sqdist(p[1],p[2]), 2);
   REP(i,3,n) REMIN(mini, mp(sqdist(p[1],p[i]), i));
   int k = mini.se;
   pair<real,int> mini2(8LL*INF*INF,-1);
   REP(i,2,n) if (i != k) if (det(p[1],p[k],p[i]) != 0) REMIN(mini2, mp(sqdist(p[1], p[i]), i));
   int j = mini2.se;
   printf("%d %d %d", 1, k, j);
}
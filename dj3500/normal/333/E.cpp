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
#define ll int
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

#define pt pair<ll,ll>
#define x first
#define y second
namespace geo {
//bool praword(pt X,pt Y,pt Z){return det(X,Y,Z)<=eps;}
// wersja oszczedna:
bool praword(pt X,pt Y,pt Z){return ((X.x-Z.x)*(Y.y-Z.y)-(X.y-Z.y)*(Y.x-Z.x))<=0;}
// dla calkowitych zmienic na det(X,Y,Z)<=0

// zwraca otoczke w kierunku przeciwzegarowym, 
// kolejne wierzcholki wyniku nie sa wspolliniowe
// dziala tez na pii po zmianie w praword x->fi, y->se i pt->pii
// nie trzeba wtedy definiowac pt ani == ani <
vector<pt> otoczka(const vector<pt> &ab) {
    //sort(ab.begin(),ab.end());
    //ab.erase(unique(ab.begin(),ab.end()),ab.end());
    int l=SZ(ab),i,j,k;
    vector<pt> wyn(l+1);
    if (l<3) return ab;
    j=0;
    for(i=0;i<l;i++) {
        while (j-2>=0 && praword(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    k=j;
    for(i=l-2;i>=0;i--) {
        while (j-1>=k && praword(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    if (wyn[j-1]==wyn[0]) j--;
    return vector<pt>(wyn.begin(),wyn.begin()+j);
}

int n;
inline int nxt (int j) {
   if (j < n-1) return j+1;
   else return 0;
}
inline ll dist (const pt &a, const pt &b) {
   return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
ll najdalsze (const vector<pt> &w) {
   if (SZ(w) <= 1) return 0;
   vector<pt> v = otoczka(w);
   n = SZ(v);
   int j = 0;
   ll res = 0;
   FOR(i,n) {
      while (dist(v[nxt(j)], v[i]) > dist(v[j], v[i])) j = nxt(j);
      REMAX(res, dist(v[j], v[i]));
   }
   return res;
}
};

//#define real double

int main () {
   wez(n)
   vector<pt> v;
   FOR(i,n) {
      wez2(a,b);
      v.pb(mp(a,b));
   }
   sort(ALL(v));
   ll from = 1, to = 1001001001, best = 0;
   vector<pt> inne;
   while (from <= to) {
      ll czteryr2 = (from + to) / 2;
      bool dasie = 0;
      FOR(i,n) {
         inne.clear();
         FOR(j,n) if (geo::dist(v[i], v[j]) >= czteryr2) inne.pb(v[j]);
         if (geo::najdalsze(inne) >= czteryr2) { dasie = 1; break; }
      }
      if (dasie) {
         from = czteryr2 + 1;
         best = czteryr2;
      } else {
         to = czteryr2 - 1;
      }
   }
   cout << setprecision(10) << fixed << sqrt(best / 4.0);
}
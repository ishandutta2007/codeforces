#define SYF freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

double sqr (int a) { return (double)a*a; }

struct Point {
   int x,y;
   int number, ktory;
   Point(int _x = 0, int _y = 0) : x(_x),y(_y) {}
   bool operator == (Point &a) {
      return a.x == x && a.y == y;
   }
};
bool OrdXY(Point *a, Point *b) {
   return a->x == b->x ? a->y < b->y : a->x < b->x;
}
bool OrdYX(Point *a, Point *b) {
   return a->y == b->y ? a->x < b->x: a->y < b->y;
}

struct NearestPoints {
   vector<Point*> l;
   Point *p1, *p2;
   double dist;
   void Filter(vector<Point*> &vecl, double p) {
      int s = 0;
      FOR(x,SZ(vecl))
         if (sqr(vecl[x]->x - p) <= dist) vecl[s++] = vecl[x];
      vecl.resize(s);
   }
   void Calc (int p, int k, vector<Point*> &ys) {
      if (k - p > 1) {
         vector<Point*> lp, rp;
         int c = (k+p-1)/2;
         FOREACH(it,ys)
            if (OrdXY(l[c], *it)) rp.pb(*it); else lp.pb(*it);
         Calc(p, c+1, lp);
         Calc(c+1, k, rp);
         Filter(lp, l[c]->x);
         Filter(rp, l[c]->x);
         int p = 0; double k; int rps = SZ(rp)-1;
         FOREACH(it,lp) {
            while (p < rps && rp[p+1]->y < (*it)->y) p++;
            REP(x,max(0,p-2),min(rps,p+1))
               if (dist > (k = sqr((*it)->x - rp[x]->x) + sqr((*it)->y - rp[x]->y))) {
                  // zmiana to ta linijka:
                  if ((*it)->number != rp[x]->number) {
                     dist = k;
                     p1 = *it;
                     p2 = rp[x];
                  }
               }
         }
      }
   }
   NearestPoints(vector<Point> &p) {
      FOREACH(it,p) l.pb(&(*it));
      sort(ALL(l), OrdXY);
      FORI(x,SZ(l)-1)
         if (l[x-1]->x == l[x]->x && l[x-1]->y == l[x]->y) {
            // zmiana to ta linijka:
            if (l[x-1]->number != l[x]->number) {
               dist = 0;
               p1 = l[x-1]; p2 = l[x]; return;
            }
         }
      dist = double(INF)*double(INF);
      vector<Point*> v = l;
      sort(ALL(v), OrdYX);
      Calc(0, SZ(l), v);
      dist = sqrt(dist);
   }
};

/*int main () {

   Point p;
   cin >> n;
   FOR(x,n) {
      cin >> p.x >> p.y;
      l.pb(p);
   }
   NearestPoints str(l);hfghfghfghhf
   DBG(str.dist)
   DBG(mp(str.p1->x, str.p1->y))
   DBG(mp(str.p2->x, str.p2->y))
}*/

int main () {
   SYF
   wez(n)
   vector<Point> vec;
   FORI(i,n) {
      wez2(x,y)
      Point p[5];
      FORI(u,4) p[u].x = x, p[u].y = y, p[u].ktory = u, p[u].number = i;
      p[2].x *= -1;
      p[4].x *= -1;
      p[3].y *= -1;
      p[4].y *= -1;
      FORI(u,4) vec.pb(p[u]);
   }
   NearestPoints str(vec);
   printf("%d %d %d %d", str.p1->number, str.p1->ktory, str.p2->number, 5 - str.p2->ktory);
}
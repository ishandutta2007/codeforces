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
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);


int a[200007];
int occ[1000007];
ll curres = 0;
inline void add (int i) {
   int k = a[i];
   curres += (ll)k*(2*(occ[k]++) + 1);
}
inline void erase (int i) {
   int k = a[i];
   curres -= (ll)k*(2*(occ[k]--) - 1);
}
ll getres () {
   return curres;
}

// Usage: set Q, sq=sqrt(n), q, le[0..q-1], ri[0..q-1] and
// provide add, erase, getres. Then go() fills in res[0..q-1].
#define Q 200006 
int sq, q, le[Q], ri[Q]; // q = number of queries [0 .. q-1]
ll res[Q]; // output
bool comp (int i, int j) {
   return mp(le[i] / sq, ri[i]) < mp(le[j] / sq, ri[j]);
}
void go () {
   vi tests;
   FOR(i,q) tests.pb(i);
   sort(ALL(tests),comp);
   int cl = 1, cr = 0; // [cl,cr]
   FOREACH(it,tests) {
      int i = *it, l = le[i], r = ri[i];
      while (cl > l) add(--cl);
      while (cr < r) add(++cr);


      while (cl < l) erase(cl++);
      while (cr > r) erase(cr--);
      res[i] = getres();
   }
}

int main () {
   int n;
   scanf("%d %d", &n, &q);
   sq = sqrt(n);
   FORI(i,n) scanf("%d", a+i);
   FOR(i,q) scanf("%d %d", le+i, ri+i);
   go();
   FOR(i,q) printf("%I64d\n", res[i]);
}
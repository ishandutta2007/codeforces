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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int ufn;
struct UnionFind {
   vi tab, ile;

   UnionFind() : // tworzy UF na 0, 1, ..., n-1
      tab(ufn), ile(ufn,1) {
      FOR(i,ufn) tab[i] = i;
   }

   int find(int a) {
      if (tab[a] == a) return a;
      return a = find(tab[a]);
   }

   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
      a = find(a), b = find(b);
      if (a==b) return 0;
      if (ile[a] <= ile[b]) {
         ile[b] += ile[a];
         tab[a] = b;
      } else {
         ile[a] += ile[b];
         tab[b] = a;
      }
      return 1;
   }
};

#define N 10007
int a[N], b[N], n;

int main () {
   scanf("%d", &n);
   ufn = n + 5;
   wez(m)
   UnionFind *pref = new UnionFind[m+5], *suf = new UnionFind[m+5];
   FORI(i,m) scanf("%d %d", a+i, b+i);
   FORI(i,m) {
      pref[i] = pref[i-1];
      pref[i].unia(a[i], b[i]);
   }
   REPD(i,m,1) {
      suf[i] = suf[i+1];
      suf[i].unia(a[i], b[i]);
   }
   TESTS {
      wez2(l,r)
      UnionFind uf = pref[l-1];
      vi vec[506];
      FORI(i,n) vec[suf[r+1].find(i)].pb(i);
      FORI(i,n) {
         FOR(u,SZ(vec[i])-1) uf.unia(vec[i][u], vec[i][u+1]);
      }
      int skl = 0;
      FORI(i,n) if (uf.find(i) == i) skl++;
      pisz(skl);
   }
}
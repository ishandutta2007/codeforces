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
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

struct Node {
   Node* x[26];
   Node () { FOR(i,26) x[i] = 0; }
   void wstaw (const char *s) {
      if (*s == 0) return;
      int c = (*s) - 'a';
      if (x[c] == 0) {
         x[c] = new Node();
      }
      x[c]->wstaw(s+1);
   }
   bool go (bool atleaf) {
      bool isleaf = 1, has0 = 0;
      FOR(i,26) if (0 != x[i]) {
         isleaf = 0;
         bool g = x[i]->go(atleaf);
         if (g == 0) {
            has0 = 1;
         }
      }
      if (isleaf) return atleaf;
      return has0;
   }
};

#define N 100007
char s[N];

int main () {
   wez2(n,k)
   Node root;
   while (n--) {
      scanf("%s", s);
      root.wstaw(s);
   }
   bool winnable = root.go(0);
   bool loseable = root.go(1);
   //DBG(winnable)DBG(loseable)
   if (winnable) {
      if (loseable) {
         printf("First");
      } else {
         if (k % 2 == 1) {
            printf("First");
         } else {
            printf("Second");
         }
      }
   } else {
      printf("Second");
   }
}
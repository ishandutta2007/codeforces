#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}
ll nwd (ll a, ll b) {
   if (b==0) return a;
   return nwd(b, a%b);
}

ll nww(ll a, ll b) {
   return a/nwd(a,b)*b;
}

struct UnionFind {
   vector<int> tab,ile;
   int size;
   
   UnionFind(int _size) : // tworzy UF na 0, 1, ..., n-1
      size(_size), tab(_size), ile(_size,1) {
      FOR(i,size) tab[i] = i;
   }
 
   int find(int a) {
        if (tab[a]==a) return a;
        int fa = find(tab[a]);
        tab[a] = fa;
        return fa;
   }
 
   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
        int fa = find(a);
        int fb = find(b);
 
        if (fa==fb) return false;
        if (ile[fa] <= ile[fb]) {
                ile[fb] += ile[fa];
                tab[fa] = fb;
        } else {
                ile[fa] += ile[fb];
                tab[fb] = fa;
        }
        return true;
   }
   
   int ileKlas() { // ile jest klas abstrakcji? UWAGA: zakada, e wszystkie numerki s wykorzystane
   // UWAGA: funkcja nieprzetestowana
      int w = 0;
      FOR(i,size) if (tab[i]==i) ++w;
      return w;
   }
};


int a[1000002];
const int MAX = 10000000;
int main () {
   wez(k)
   FOR(i,k) scanf("%d",a+i);
   sort(a,a+k);
   
   UnionFind uf(k);
   
   for (int n = 1; n*n <= MAX; ++n) {
      for (int m = (n & 1) ? 2 : 1; m*m <= MAX; m+=2) {
         if (nwd(n,m) == 1) {
//            if (n==2 && m==1) DBG(1)
            int duze = n*n+m*m;
            int pos = lower_bound(a,a+k,duze)-a;
            if (pos < k && a[pos] == duze) {
               int male = n*n-m*m;
               int pos2 = lower_bound(a,a+k,male)-a;
               if (pos2 < k && a[pos2] == male) {
//                     DBG(male)DBG(duze)
                  uf.unia(pos,pos2);
               }
               
               ll inne = 2*(ll)n*m;
               if (inne <= MAX) {
                  int pos3 = lower_bound(a,a+k,inne)-a;
                  if (pos3 < k && a[pos3] == inne) {
//                     DBG(duze)DBG(inne)
                     uf.unia(pos,pos3);
                  }
               }
            }
         }
      }
   }
   
   for (ll m = 1; 2*m <= MAX; ++m) {
      for (ll n = m+1; 2*n*m <= MAX && n*n-m*m <= MAX; n += 2) {
         if (nwd(n,m)==1) {
            ll duze = n*n-m*m;
            if (duze >= 0) {
               int pos = lower_bound(a,a+k,duze)-a;
               if (pos < k && a[pos] == duze) {
                  int male = 2*n*m;
                  int pos2 = lower_bound(a,a+k,male)-a;
                  if (pos2 < k && a[pos2] == male) {
//                     DBG(duze)DBG(male)
                     uf.unia(pos,pos2);
                  }
               }
            }
         }
      }
   }
            
   pisz(uf.ileKlas());        
}
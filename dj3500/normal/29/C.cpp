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
#define INF (int)2e9
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

int main () {
   wez(n);
   multimap<int, int> m;
   vector<int> wynik, keys;
   FORI(i,n) {
      int a,b;
      scanf("%d %d",&a,&b);
      m.insert(mp(a,b));
      m.insert(mp(b,a));
      keys.pb(a);
      keys.pb(b);
   }

   wynik.pb(-666);
   FOR(i,keys.size()) {
      if (m.count(keys[i]) == 1) {
         wynik.pb(keys[i]);
         break;
      }
   }
   
   for (int ktory = 2; ktory <= n+1; ++ktory) {
      pair<map<int,int>::iterator, map<int,int>::iterator> p = m.equal_range(wynik[ktory-1]);
      for (map<int,int>::iterator it = p.first; it != p.second; ++it) {
         if (it->second != wynik[ktory-2]) {
            wynik.pb(it->second);
            break;
         }
      }
   }
   
   FORI(i,n+1) {
      printf("%d ",wynik[i]);
   }
   return 0;     
}
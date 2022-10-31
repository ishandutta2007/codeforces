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

int n,k;
string p,lim;
char must[1000];

bool foundwrong () {
   FOR(i,n-p.size()+1) {
      if (lim[i] == '0') {
         bool matches = true;
         FOR(j,p.size()) {
            if (must[i+j] != p[j]) {
               matches = false;
               break;
            }
         }
         if (matches) return true;
      }
   }
   return false;
}

int main () {
   cin >> n >> k;
   cin >> p;
   cin >> lim;
   
   FOR(i,n) must[i] = 0;
   must[n] = 0;
   
   FOR(i,n-p.size()+1) {
      if (lim[i] == '1') {
         FOR(j,p.size()) {
            // ustaw i+j na p[j]
            if ((must[i+j] == 0) || (must[i+j] == p[j])) {
               must[i+j] = p[j];
            } else {
               cout << "No solution" << endl;
               return 0;
            }
         }
      }
   }
   
   FOR(i,n) {
      if (!must[i]) {
         char lit;
         for (lit = 'a'; lit < 'a'+k; ++lit) {
            must[i] = lit;
            if (!foundwrong()) break;
         }
         if (lit == 'a'+k) {
            cout << "No solution" << endl;
            return 0;
         }
      }
   }
   
   if (foundwrong()) {
      cout << "No solution" << endl;
      return 0;
   }
      
   cout << must << endl;
}
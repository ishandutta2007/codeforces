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

vector<int> v;
int n;

int checkwyw (vector<int> &a) {
   if (a.size() <= 2) return true;
   int f = a[0], s = a[1];
   
   bool ok = true;
   for (int i = 2; i < a.size(); ++i) {
      if (f * a[i] != s * a[i-1]) {
         ok = false;
         break;
      }
   }
   return ok;
}
   
   

int check (vector<int> w) {
   if (w.size() <= 2) return 0;
   if (checkwyw(w)) return 0;
   // wywalamy a[0]
   vector<int> ww;
   FOR(i,w.size()) if (i!=0) ww.pb(w[i]);
   if (checkwyw(ww)) return 1;
   //wywalamy a[1]
   ww.clear();
   FOR(i,w.size()) if (i!=1) ww.pb(w[i]);
   if (checkwyw(ww)) return 1;
   
   int f = w[0], s = w[1];
   for (int i = 2; i < w.size(); ++i) {
      if (f*w[i] != s*w[i-1]) {
         ww.clear();
         FOR(k,w.size()) if (k!=i) ww.pb(w[k]);
         if (checkwyw(ww)) return 1;
         else return 2;
      }
   }
   // tu nie dojdziemy
   return 0;
}

int main () {
   scanf("%d",&n);
   FOR(i,n) {wez(fdg);v.pb(fdg);}
   
   int zero = 0;
   FOR(i,n) if (v[i]==0) ++zero;
   if (zero) {
      int nonzero = 0;
      FOR(i,n) if (v[i] != 0) ++nonzero;
      
      if (nonzero == 0) {
         printf("0");
         return 0;
      }
      
      // sa zera i niezera
      
      if (nonzero == 1) {
         // czy to ten pierwszy?
         if (v[0] != 0) printf("0");
         else printf("1");
         return 0;
      }
      
      // nonzero >= 2, zero >= 1
      
      if (zero == 1) {
         vector<int> w;
         FOR(i,n) if (v[i] != 0) w.pb(v[i]);
         bool dasie = checkwyw(w);
         if (dasie) printf("1");
         else printf("2");
         return 0;
      }
      
      // nonzero >= 2, zero >= 2
      if (nonzero == 2) {
         if (v[0] != 0) printf("1");
         else printf("2");
         return 0;
      }
            
      // nonzero >= 3, zero >= 2
      printf("2");
      return 0;
   }
   
   // brak zer, n >= 2
   pisz(check(v));
   return 0;
}
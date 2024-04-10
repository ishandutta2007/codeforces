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

int miejsce[300005];
bool jestpoprz[300005];

int main () {
   wez(n)
   FORI(i,3*n) {
      wez(a)
      miejsce[a] = i;
      jestpoprz[i] = false;
   }
   
   vector<int> in;
   FORI(i,3*n) {wez(a) in.pb(a);}
   wez(k)
   int pos = 0;
   
   vector<int> poprz;
   FORI(i,n) {
      int a = in[pos];
      int b = in[pos+1];
      int c = in[pos+2];
      pos += 3;
      poprz.pb(a);poprz.pb(b);poprz.pb(c);
      jestpoprz[a] = jestpoprz[b] = jestpoprz[c] = true;
      if (a == k || b == k || c == k) {
         int a1,a2;
         if (a == k) {
            a1 = b; a2 = c;
         } else if (b == k) {
            a1 = a; a2 = c;
         } else {
            a1 = a; a2 = b;
         }
         if (miejsce[k] < miejsce[a1] && miejsce[k] < miejsce[a2]) {
            // jest kapitanem
            int m1 = min(a1,a2);
            int m2 = max(a1,a2);
            
            vector<int> zatrz;
            FORI(j,3*n) if (j!=k) {
               if (j == m2) {
                  printf("%d ",m2);
                  FOR(u,zatrz.size()) printf("%d ",zatrz[u]);
                  for (int v = j+1; v <= 3*n; ++v) if (v!=k) printf("%d ",v);
                  break;
               }
               if (!jestpoprz[j]) {
                  zatrz.pb(j);
               } else {
                  printf("%d ",j);
               }  
            }
            
            //sort(poprz.begin(),poprz.end());
            //FOR(j,poprz.size()) if (poprz[j] != k) printf("%d ",poprz[j]);
            //FORI(j,3*n) if(!jestpoprz[j]) printf("%d ",j);
         } else {
            // nie jest kapitanem
            FORI(j,3*n) if (j!=k) printf("%d ",j);
         }
         break;
      }
   }
            
}
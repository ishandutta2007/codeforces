#include <iostream>

#include <stack>
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

int cutheadsh[202],cutheadst[202],cuttailsh[202],cuttailst[202];
int odw[202][202], stan[202][202], ml[202][202];

int main () {
   wez(hi);wez(ti);
   wez(R);
   wez(n);
   FORI(i,n) scanf("%d %d",cutheadsh+i, cutheadst+i);
   wez(m);
   FORI(i,m) scanf("%d %d",cuttailsh+i, cuttailst+i);
   
   bool drawposs = false;
   int biggestfail = 0;
   
   FORI(i,200) FORI(j,200) odw[i][j] = stan[i][j] = ml[i][j] = 0;
   
   {
   deque<pair<pair<int,int>, int> > kol;
   kol.pb(mp(mp(hi,ti),0));
   while (!kol.empty()) {
      int h = kol.front().first.first, t = kol.front().first.second, d = kol.front().second;
      kol.pop_front();
      
      if (h==0 && t==0) {
         printf("Ivan\n%d",d);
         return 0;
      }
      if (h+t > R) {
         continue;
      }
      if (odw[h][t]) {
         continue;
      }
      odw[h][t] = true;
      
      FORI(i,min(n,h)) {
         int newh = h - i + cutheadsh[i];
         int newt = t + cutheadst[i];
         kol.pb(mp(mp(newh,newt),d+1));
      }
      FORI(i,min(m,t)) {
         int newh = h + cuttailsh[i];
         int newt = t - i + cuttailst[i];
         kol.pb(mp(mp(newh,newt),d+1));
      }
   }
   }
   // teraz znalezc cykle!
   vector<pair<int,int> > topo;
   {
   stack<pair<pair<int,int>, int> > kol;
   kol.push(mp(mp(hi,ti),0));
   while (!kol.empty()) {
      int h = kol.top().first.first, t = kol.top().first.second, d = kol.top().second;
      kol.pop();
      
      if (d == -1) {
         stan[h][t] = 2;
         topo.pb(mp(h,t));
         continue;
      }
      if (h+t > R) {
         continue;
      }
      if (stan[h][t] == 2) {
         continue;
      }
      if (stan[h][t] == 1) {
         //cykl
         printf("Draw");
         return 0;
      }
      stan[h][t] = 1;

      kol.push(mp(mp(h,t),-1));      
      FORI(i,min(n,h)) {
         int newh = h - i + cutheadsh[i];
         int newt = t + cutheadst[i];
         kol.push(mp(mp(newh,newt),d+1));
      }
      FORI(i,min(m,t)) {
         int newh = h + cuttailsh[i];
         int newt = t - i + cuttailst[i];
         kol.push(mp(mp(newh,newt),d+1));
      }
   }
   }
   
   //if (d > biggestfail) biggestfail = d;
   for (int i = topo.size()-1; i >= 0; --i) {
      int h = topo[i].first, t = topo[i].second;
      //DBG(h)DBG(t)
      FORI(i,min(n,h)) {
         int newh = h - i + cutheadsh[i];
         int newt = t + cutheadst[i];
         if (newh+newt <= R) {
            if (ml[newh][newt] <= ml[h][t] + 1) ml[newh][newt] = ml[h][t] + 1;
         } else {
            if (ml[h][t] + 1 > biggestfail) biggestfail = ml[h][t] + 1;
         }
      }
      FORI(i,min(m,t)) {
         int newh = h + cuttailsh[i];
         int newt = t - i + cuttailst[i];
         if (newh+newt <= R) {
            if (ml[newh][newt] <= ml[h][t] + 1) ml[newh][newt] = ml[h][t] + 1;
         } else {
            if (ml[h][t] + 1 > biggestfail) biggestfail = ml[h][t] + 1;
         }
      }
      
   }
   
   printf("Zmey\n%d",biggestfail);
}
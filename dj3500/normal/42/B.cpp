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

int main () {
   string s1, s2, s3, s4;
   cin >> s1 >> s2 >> s3 >> s4;
   
   bool zagr[8][8];
   FOR(i,8)FOR(j,8) zagr[i][j] = 0;
   
   int bkx = s3[0] - 'a';
   int bky = s3[1] - '1';   
   
   int x,y;
   x = s1[0] - 'a';
   y = s1[1] - '1';
   for (int i = x+1; i < 8; ++i) {
      if (bkx == i && bky == y) {
         break;
      } else {
         zagr[i][y] = 1;
      }
   }
   for (int i = x-1; i >= 0; --i) {
      if (bkx == i && bky == y) {
         break;
      } else {
         zagr[i][y] = 1;
      }
   }
   for (int j = y+1; j < 8; ++j) {
      if (bkx == x && bky == j) {
         break;
      } else {
         zagr[x][j] = 1;
      }
   }
   for (int j = y-1; j >= 0; --j) {
      if (bkx == x && bky == j) {
         break;
      } else {
         zagr[x][j] = 1;
      }
   }
   
   // zmienic
   x = s2[0] - 'a';
   y = s2[1] - '1';
   for (int i = x+1; i < 8; ++i) {
      if (bkx == i && bky == y) {
         break;
      } else {
         zagr[i][y] = 1;
      }
   }
   for (int i = x-1; i >= 0; --i) {
      if (bkx == i && bky == y) {
         break;
      } else {
         zagr[i][y] = 1;
      }
   }
   for (int j = y+1; j < 8; ++j) {
      if (bkx == x && bky == j) {
         break;
      } else {
         zagr[x][j] = 1;
      }
   }
   for (int j = y-1; j >= 0; --j) {
      if (bkx == x && bky == j) {
         break;
      } else {
         zagr[x][j] = 1;
      }
   }   
   
   // bialy krol
   x = s3[0] - 'a';
   y = s3[1] - '1';
   if (x != 0) zagr[x-1][y] = 1;
   if (x != 7) zagr[x+1][y] = 1;
   if (y != 0) zagr[x][y-1] = 1;
   if (y != 7) zagr[x][y+1] = 1;
   if (x != 0 && y != 0) zagr[x-1][y-1] = 1;
   if (x != 0 && y != 7) zagr[x-1][y+1] = 1;
   if (x != 7 && y != 0) zagr[x+1][y-1] = 1;
   if (x != 7 && y != 7) zagr[x+1][y+1] = 1;
   
   x = s4[0] - 'a';
   y = s4[1] - '1';
   bool mat = true;
   if (x != 0) if (!zagr[x-1][y]) mat = false;
   if (x != 7) if (!zagr[x+1][y]) mat = false;
   if (y != 0) if (!zagr[x][y-1]) mat = false;
   if (y != 7) if (!zagr[x][y+1]) mat = false;
   if (x != 0 && y != 0) if (!zagr[x-1][y-1]) mat = false;
   if (x != 0 && y != 7) if (!zagr[x-1][y+1]) mat = false;
   if (x != 7 && y != 0) if (!zagr[x+1][y-1]) mat = false;
   if (x != 7 && y != 7) if (!zagr[x+1][y+1]) mat = false;
   if (!zagr[x][y]) mat = false;
   
   /*FOR(i,8){
      FOR(j,8) printf("%d", zagr[i][j]);
      printf("\n");
   }*/
   
   printf(mat ? "CHECKMATE\n" : "OTHER\n");
}
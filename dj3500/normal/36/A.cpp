#include <iostream>
#include <fstream>
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
#define wez(n) int (n); fscanf(fp, "%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

string a;

int main () {
   ifstream f("input.txt");
   int n;
   f >> n;
   f >> a;
   
   //DBG(a[2]) DBG(a[3])

   int w = -1;
   bool fail = false;
   FORI(i,n) if (a[i-1] == '1') {
      //DBG(i)
      bool jest = false;
      int j;
      for (j = i+1; j <= n; ++j) {
         if (a[j-1] == '1') { jest = true; break; }
      }
      //DBG(jest)
      if (!jest) break;
      //DBG(j)
      if (w == -1) w = j-i;
      else if (w != j-i) {
         fail = true;
      }
   }
   ofstream ff("output.txt");
   if (fail) ff << "NO"; else ff << "YES";
}
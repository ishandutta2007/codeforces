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
   string s;
   cin >> s;
   int uc = 0, lc = 0;
   FOR(i,s.length()) {
      if (s[i] >= 'A' && s[i] <= 'Z') ++uc;
      else ++lc;
   }
   FOR(i,s.length()) {
      if (uc > lc) {
         if (s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
      } else {
         if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= 'A' - 'a';
      }
   }
   cout << s;
         
}
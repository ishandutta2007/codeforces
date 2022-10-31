#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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
   char s[100002];
   scanf("%s",s);
   int n = strlen(s);
   sort(s,s+n);
   ll ciag = 1, wynik = 0;
   //char ost = s[0];
   for (int i = 1; i < n; ++i) {
      if (s[i] == s[i-1]) {
         ++ciag;
      } else {
         wynik += ciag*ciag;
         ciag = 1;
      }
   }
   wynik += ciag*ciag;
   printf("%I64d",wynik);
}
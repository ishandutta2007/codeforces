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

bool present[300];

int main () {
   wez(k)
   string s;
   cin >> s;
   FOR(i,300) present[i] = false;
   FOR(i,s.length()) {
      int j = s.length()-1-i;
      if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
         printf("IMPOSSIBLE\n");
         return 0;
      }
      if (s[i] == '?') s[i] = s[j];
   }
   FOR(i,s.length()) if (s[i] != '?') present[s[i]] = true;
   char now = 'a'+k-1;
   
   int len = (s.length() % 2) ? (s.length()/2 + 1) : (s.length() / 2);
   for (int i = len-1; i >= 0; i--) {
      if (s[i] != '?') continue;
      while (now != 'a' - 1 && present[now] == true) --now;
      if (now == 'a'-1) {
         s[i] = s[s.length()-1-i] = 'a';
      } else {
         s[i] = s[s.length()-1-i] = now;
         present[now] = true;
      }
   }
   FOR(i,k) if (!present['a'+i]) { printf("IMPOSSIBLE\n"); return 0; }
   cout << s;
}
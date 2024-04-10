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
   string s[3];
   string w[3] = {"F","M","S"};
   cin >> s[0] >> s[1] >> s[2];
   
   FOR(i,3) {
      if (s[i] == "rock" && s[(i+1)%3] == "scissors" && s[(i+2)%3] == "scissors") {
         cout << w[i];
         return 0;
      }
      if (s[i] == "paper" && s[(i+1)%3] == "rock" && s[(i+2)%3] == "rock") {
         cout << w[i];
         return 0;
      }
      if (s[i] == "scissors" && s[(i+1)%3] == "paper" && s[(i+2)%3] == "paper") {
         cout << w[i];
         return 0;
      }
   }
   cout << "?";
   return 0;
   
}
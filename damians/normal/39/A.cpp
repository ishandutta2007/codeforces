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
char s[100000];

bool myfunction (pair<int,bool> i,pair<int,bool> j) { return (i.first<j.first); }

int main () {
   wez(a);
   s[0] = '+';
   scanf("%s",s+1);
   vector<pair<int,bool> > v;
   int pos = 0;
   while (s[pos] != 0) {
      pair<int,bool> nowy;
      if (s[pos] == '+') {
         nowy.first = 1;
      } else if (s[pos] == '-') {
         nowy.first = -1;
      } else {
         printf("ani plus ani minus, pos = %d\n",pos);
         return 1;
      }
      pos++;
      
      if (s[pos] >= '0' && s[pos] <= '9') { // jest coefficient
         int coeff = 0;
         while (s[pos] >= '0' && s[pos] <= '9') {
            coeff = 10*coeff + (s[pos] - '0');
            pos++;
         }
         if (s[pos] != '*') {
            printf("po coefficiencie nie ma *\n");
            return 1;
         }
         ++pos;
         nowy.first *= coeff;
      }
      

      nowy.second = (s[pos] == '+');
      pos += 3;
      v.pb(nowy);
   }
   
   sort(v.begin(),v.end(),myfunction);
   int wyn = 0;
   FOR(i,v.size()) { //printf("%d %d\n",v[i].first,v[i].second);
      if (v[i].second) ++a;
      wyn += v[i].first * a;
      if (!v[i].second) ++a;
   }
   pisz(wyn);
}
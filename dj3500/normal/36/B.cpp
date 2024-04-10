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
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

char s[6][245][245];

int main () {
  ifstream f("input.txt");
  ofstream of("output.txt");
  int n,k;
  f >> n >> k;
  string ss;
  FOR(i,n) {
     f >> ss;
     FOR(j,n) {
        s[1][i][j] = ss[j];
     }
  }
  
  int potega = n;
  
  for (int krok = 2; krok <= k; ++krok) {
     FOR(i,potega) FOR(j,potega) {
        if (s[krok-1][i][j] == '*') {
           for (int nowei = i*n; nowei <= i*n + n - 1; ++nowei) {
              for (int nowej = j*n; nowej <= j*n + n - 1; ++nowej) {
                 s[krok][nowei][nowej] = '*';
              }
           }
        } else {
           for (int nowei = i*n; nowei <= i*n + n - 1; ++nowei) {
              for (int nowej = j*n; nowej <= j*n + n - 1; ++nowej) {
                 s[krok][nowei][nowej] = s[1][nowei - i*n][nowej - j*n];
              }
           }
        }
     }      
     
     potega *= n;
  }
  
  FOR(i,potega) {
     s[k][i][potega] = 0;
     of << s[k][i] << "\n";
  }
}
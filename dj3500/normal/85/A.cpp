#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
using namespace std;
#define pb push_back
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

char s[200][200];

void tile (int n) {
      bool ev = false;
      for (int i = 0; i < n; i+=2, ev=!ev ) {
         s[0][i]=s[0][i+1]=s[3][i]=s[3][i+1]= ev ? 'a' : 'b';
         if (i != 0) {
            s[1][i-1]=s[1][i]= ev ? 'e' : 'f';
            s[2][i-1]=s[2][i]= ev ? 'c' : 'd';
         }
      }
      s[1][0]=s[2][0]='j';
      s[1][n-1]=s[2][n-1]='k';
}

int main () {
   wez(n)
   FOR(r,4) s[r][n]=0;
/*   if (n==1) {
      s[0][0] = s[1][0] = 'a';
      s[2][0]=s[3][0]='b';
      printf("-1");
      return 0;
   } else*/ if (n%2 == 0) {
      tile(n);
   } else {
      bool ev = false;
      for (int i = 0; i < n-1; i += 2, ev=!ev) {
         s[0][i]=s[0][i+1]=ev ? 'a' : 'e';
         s[1][i]=s[1][i+1]=ev ?'b':'f';
         s[2][i+1]=s[2][i+2]=ev?'c':'g';
         s[3][i+1]=s[3][i+2]=ev?'d':'h';
      }
      s[2][0]=s[3][0]='k';
      s[0][n-1]=s[1][n-1]='l';
   }
   FOR(r,4) printf("%s\n",s[r]);
}
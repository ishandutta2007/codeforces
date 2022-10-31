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
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int main () {
   IOS
   string s;
   cin >> s;
   int n = SZ(s);

   const int n1 = count(ALL(s),'1'), n0 = count(ALL(s),'0'), rest = n-n0-n1,
   all0 = n1 - (n0 + rest), all1 = (n1 + rest) - n0;
   if (all0 < 0) printf("00\n");
   if ((0 >= all0 && 0 <= all1) || (1 >= all0 && 1 <= all1)) {
      int last0=-1,last1=-1,lastp=-1;
      FOR(i,n) {
         if (s[i] == '0') last0=i;
         if (s[i] == '1') last1=i;
         if (s[i] == '?') lastp=i;
      }
      
      // maybe ?'s are determined after all!
      if (all0 == 0 || all0 == 1) {
         // have to set all ?'s to 0
         last0 = max(last0,lastp);
         lastp = -1;
      } else if (all1 == 1 || all1 == 0) {
         last1 = max(last1,lastp);
         lastp = -1;
      }
      
      if (max(last1,lastp) > last0) printf("01\n");
      if (max(last0,lastp) > last1) printf("10\n");
   }
   if (all1 > 1) printf("11\n");
}
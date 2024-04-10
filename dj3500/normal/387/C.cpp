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
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
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
   int res = 1;
   int le = 0, ri = 0;
   while (s[ri + 1] == '0') ++ri;
   while (ri != n-1) {
      int le1 = ri + 1, ri1 = le1;
      while (s[ri1 + 1] == '0') ++ri1;
      
      bool larger;
      if (ri - le > ri1 - le1) {
         larger = 1;
      } else if (ri - le < ri1 - le1) {
         larger = 0;
      } else {
         larger = 1; // equal
         for (int k = 0; k + le <= ri; ++k) {
            int l = k + le1;
            if (s[k] > s[l]) {
               larger = 1;
               break;
            } else if (s[k] < s[l]) {
               larger = 0;
               break;
            }
         }
      }
      
      ri = ri1;
      if (larger) {
         ++res;
      } else {
         res = 1;
      }
   }
   pisz(res);
}
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
   wez2(k,x)
   wez2(n,m)
   FOR(last1isA,2) FOR(first1isC,2) FOR(last2isA,2) FOR(first2isC,2) {
      int len1 = n, len2 = m;
      if (last1isA) --len1;
      if (first1isC) --len1;
      if (last2isA) --len2;
      if (first2isC) --len2;
      if (len1 < 0 || len2 < 0) continue;
      int max1 = len1 / 2, max2 = len2 / 2;
      REP(_ac1,0,max1) REP(_ac2,0,max2) {
         bool sC1 = first1isC, lA1 = last1isA, sC2 = first2isC, lA2 = last2isA;
         ll ac1 = _ac1, ac2 = _ac2;
         REP(kk,3,k) {
            bool sC3 = sC1;
            bool lA3 = lA2;
            ll ac3 = ac1 + ac2 + (lA1 && sC2);
            
            sC1 = sC2;
            lA1 = lA2;
            ac1 = ac2;

            sC2 = sC3;
            lA2 = lA3;
            ac2 = ac3;
         }
         if (x == ac2) {
            string s1, s2;
            FOR(i,_ac1) s1 += "AC";
            FOR(i,_ac2) s2 += "AC";
            FOR(i,len1 - 2*_ac1) s1 += 'X';
            FOR(i,len2 - 2*_ac2) s2 += 'X';
            if (last1isA) s1 += 'A';
            if (last2isA) s2 += 'A';
            if (first1isC) s1 = 'C' + s1;
            if (first2isC) s2 = 'C' + s2;
            printf("%s\n%s", s1.c_str(), s2.c_str());
            return 0;
         }
      }
   }
   printf("Happy new year!");
}
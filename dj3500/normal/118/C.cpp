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

char s[100005];

int main () {
   wez2(n,k)
   scanf("%s",s);

   vector<string> wyniki;
   int minkoszt = INF;

   for (char dig = '0'; dig <= '9'; ++dig) {
      string wynik = s;

      int ilerownych = 0;
      FOR(i,n) if (s[i] == dig) ++ilerownych;

      if (ilerownych < k) {
         vector<char> c;
         FORI(odleglosc,9) {
            if (isdigit(dig + odleglosc)) c.pb(dig + odleglosc);
            if (isdigit(dig - odleglosc)) c.pb(dig - odleglosc);
         }

         int jeszcze = k - ilerownych;
         FOR(d,SZ(c)) {
            int ile = 0;
            FOR(i,n) if (c[d] == s[i]) ++ile;
            if (ile < jeszcze) {
               jeszcze -= ile;
               FOR(i,n) if (c[d] == s[i]) wynik[i] = dig;
            } else {
               // juz
               if (c[d] > dig) {
                  // zamieniamy c[d] na dig, czyli zmniejszamy, lepiej jechac od lewej
                  FOR(i,n) {
                     if (c[d] == s[i]) {
                        wynik[i] = dig;
                        jeszcze--;
                        if (jeszcze == 0) break;
                     }
                  }
               } else {
                  // lepiej od prawej
                  REPD(i,n-1,0) {
                     if (c[d] == s[i]){
                        wynik[i] = dig;
                        jeszcze--;
                        if (jeszcze == 0) break;
                     }
                  }
               }

               break;
            }
         }
      } // else: jest ok

      int koszt = 0;
      FOR(i,n) koszt += abs(int(s[i]) - int(wynik[i]));
      if (minkoszt > koszt) {
         minkoszt = koszt;
         wyniki.clear();
         wyniki.pb(wynik);
      } else if (minkoszt == koszt) {
         wyniki.pb(wynik);
      }
   }

   sort(ALL(wyniki));
   pisz(minkoszt);
   printf("%s\n",wyniki[0].c_str());
}
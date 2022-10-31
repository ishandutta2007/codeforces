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
   ll n;
   cin >> n;
   int wyn = 0;
   REP(k,0,62) {
      ll from = 0, to = 1LL << 60;
      bool found = 0;
      while (from <= to && !found) {
         ll p = (from + to) / 2;
         if (double(1LL<<k) * double(2*p+1) > (1LL<<60)) {
            to = p-1;
         } else if (double(p-1)*double(2*p+1) > (1LL<<60)) {
            to = p-1;
         } else {
            ll g = (1LL<<k) * (2*p+1) + (2*p+1)*(p-1);
            if (g > n) {
               to = p-1;
            } else if (g < n) {
               from = p+1;
            } else {
               DBG(g)
               DBG(n)
               cout << (1LL<<k)*(2*p+1) << " ";
               ++wyn;
               found = 1;
            }
         }
      }
   }
   if (wyn == 0) cout << -1;
}
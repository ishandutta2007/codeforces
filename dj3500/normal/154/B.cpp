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

vector<bool> sito (int m) { // m = max_inclusive
   vector<bool> pr(m+1,1);
   pr[0] = pr[1] = 0;
   for (int x = 2; x*x <= m; ++x) if (pr[x]) for (int y = x*x; y <= m; y += x) pr[y] = 0;
   return pr;
}

vi primedivs[100007];
int nctp[100007]; // number of collider which takes up this prime number
bool collon[100007];

int main () {
   vector<bool> pr = sito(100000);
   REP(i,2,100000) if (pr[i]) for (int x = i; x <= 100000; x += i) primedivs[x].pb(i);
   //REP(i,2,18) { DBG(i)DBG(primedivs[i])}
   //DBG(primedivs[1])
   collon[1] = 0;
   REP(i,2,100000) collon[i] = nctp[i] = 0;
   wez(n)
   
   TESTS {
      char c; int x;
      scanf(" %c %d", &c, &x);
      if (c == '+') {
         if (collon[x]) {
            printf("Already on\n");
         } else {
            int confl = 0;
            FOREACH(p,primedivs[x]) {
               if (nctp[*p] != 0) confl = nctp[*p];
            }
            if (!confl) {
               printf("Success\n");
               collon[x] = 1;
               FOREACH(p,primedivs[x]) {
                  nctp[*p] = x;
               }
            } else {
               printf("Conflict with %d\n", confl);
            }
         }
      } else {
         if (collon[x]) {
            collon[x] = 0;
            printf("Success\n");
            FOREACH(p,primedivs[x]) {
               nctp[*p] = 0;
            }
         } else {
            printf("Already off\n");
         }
      }
   }
}
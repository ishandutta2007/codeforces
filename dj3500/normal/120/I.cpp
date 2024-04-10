#define SYF freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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

#define MAXN 200006
char s[MAXN];
int x[MAXN];
int sufsum[MAXN], nicesufsum[MAXN], niceprefsum[MAXN], idealsufsum[MAXN];
bool kreski[10][7] = {
   {1,1,1,0,1,1,1}, // 0
   {0,0,1,0,0,1,0}, // 1
   {1,0,1,1,1,0,1}, // 2
   {1,0,1,1,0,1,1}, // 3
   {0,1,1,1,0,1,0}, // 4
   {1,1,0,1,0,1,1}, // 5
   {1,1,0,1,1,1,1}, // 6
   {1,0,1,0,0,1,0}, // 7
   {1,1,1,1,1,1,1}, // 8
   {1,1,1,1,0,1,1}  // 9
};
int val[10][10];

int main () {
   SYF
   FOR(i,10) FOR(j,10) {
      val[i][j] = 0;
      FOR(k,7) if (kreski[i][k] && kreski[j][k]) ++val[i][j];
   }

   scanf("%s",s);
   int n = strlen(s)/2;
   FORI(i,2*n) x[i] = s[i-1] - '0';

   nicesufsum[2*n+1] = sufsum[2*n+1] = 0;
   REPD(i,2*n,n+1) {
      sufsum[i] = sufsum[i+1] + val[x[i-n]][x[i]];
      nicesufsum[i] = nicesufsum[i+1] + val[x[i-n]][x[i-n]];
   }
   // sufsum[n+1] = obecny luckiness
   //DBG(sufsum[n+1]) fhtfh fghfg

   // faza 1
   REPD(i,2*n,n+1) {
      REP(nowacyfra,x[i]+1,9) {
         // czy da sie zmienic x[i] na nowacyfre (i cokolwiek po prawej) tak by sumasuf byla wieksza?
         if (nicesufsum[i+1] + val[x[i-n]][nowacyfra] > sufsum[i]) {
            // formuj wynik
            x[i] = nowacyfra;
            int sumadotad = val[x[i-n]][nowacyfra];
            REP(j,i+1,2*n) {
               int jaka = -1;
               REP(cyfra,0,9) {
                  // czy jak wstawie te cyfre to bedzie jeszcze ok?
                  if (sumadotad + val[x[j-n]][cyfra] + nicesufsum[j+1] > sufsum[i]) {
                     jaka = cyfra;
                     break;
                  }
               }
               if (jaka == -1) printf("dupa, zle");
               x[j] = jaka;
               sumadotad += val[x[j-n]][jaka];
            }

            FORI(j,2*n) putchar('0' + x[j]);
            //printf(" faza 1");
            return 0;
         }
      }
   }

   // faza 2
   niceprefsum[0] = 0;
   REP(i,1,n) {
      niceprefsum[i] = niceprefsum[i-1] + val[x[i]][x[i]];
   }

   REPD(i,n,1) {
      REP(nowacyfra,x[i]+1,9) {
         if (sufsum[n+1] < 7*(n-i) + val[nowacyfra][nowacyfra] + niceprefsum[i-1]) {
            // formuj wynik
            x[i] = nowacyfra;
            int sumadotad = val[nowacyfra][nowacyfra] + niceprefsum[i-1];
            REP(j,i+1,n) {
               int jaka = -1;
               REP(cyfra,0,9) {
                  if (sufsum[n+1] < sumadotad + val[cyfra][cyfra] + 7*(n-j)) {
                     jaka = cyfra;
                     break;
                  }
               }
               if (jaka == -1) printf("fail, zle");
               x[j] = jaka;
               sumadotad += val[jaka][jaka];
            }

            idealsufsum[n+1] = 0;
            REPD(j,n,1) idealsufsum[j] = idealsufsum[j+1] + val[x[j]][x[j]];

            sumadotad = 0;
            REP(j,n+1,2*n) {
               int jaka = -1;
               REP(cyfra,0,9) {
                  if (sufsum[n+1] < sumadotad + idealsufsum[j+1-n] + val[x[j-n]][cyfra]) {
                     jaka = cyfra;
                     break;
                  }
               }
               if (jaka == -1) printf("zlo, zle");
               x[j] = jaka;
               sumadotad += val[x[j-n]][jaka];
            }

            FORI(j,2*n) putchar('0' + x[j]);
            return 0;
         }
      }
   }

   // faza 3
   printf("-1");
}
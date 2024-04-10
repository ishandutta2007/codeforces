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


#define LIMIT 5005
int n;
char s[LIMIT][LIMIT];

char stan_dfs[LIMIT+1];
int ojciec[LIMIT+1];
#include <stack>
vi dfs () {
   const char BIALY = 0, SZARY = 1, CZARNY = 2;
   memset(stan_dfs,BIALY,n+1);

   FORI(i,n) {
      if (stan_dfs[i] != BIALY) continue;
      stack<pii> kol;
      kol.push(mp(i,0));
      while (!kol.empty()) {
         int v = kol.top().first;
         int skad = kol.top().second;
         kol.pop();

         if (v < 0) {
            // wychodzimy z wierzcholka

            stan_dfs[-v] = CZARNY;
            continue;
         }

         if (stan_dfs[v] == CZARNY) {
            // juz tu bylimy

            continue;
         }
         if (stan_dfs[v] == SZARY) {
// mamy cykl: v <- skad <- ojciec[skad] <- ojciec[ojciec[skad]] <- ... <- v
            ojciec[v] = skad;
            int w = v;
            vi wyn;
            do {
               wyn.pb(w);
               w = ojciec[w];
            } while (w != v);
            return wyn;

         } else { // BIALY
            // odwiedzamy nowy wierzcholek

            ojciec[v] = skad;
            stan_dfs[v] = SZARY;
            kol.push(mp(-v,0));
            FORI(j,n) if (s[v][j] == '1') {
               if (j != skad) {
                  kol.push(mp(j,v));
               }
            }
         }
      }
   }
   return vi();
}

char temp[LIMIT];

int main () {
   scanf("%d",&n);
   FOR(i,n) {
      scanf("%s",temp);
      FOR(j,n) s[i+1][j+1] = temp[j];
   }
   vi wyn = dfs();
   if (wyn.empty()) {
      pisz(-1);
   } else {
      while (SZ(wyn) > 3) {
         int przedost = wyn[SZ(wyn) - 2];
         if (s[przedost][wyn[0]] == '1') {
            printf("%d %d %d\n",wyn[0],wyn[SZ(wyn)-1],przedost);
            return 0;
         } else {
            wyn.pop_back();
         }
      }
      printf("%d %d %d\n",wyn[2],wyn[1],wyn[0]);
   }
}
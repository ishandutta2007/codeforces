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
#define INF (int)1e9
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

vi adj[100004];
ll pi[100004],dr[100004];
ll beav[100004];

#define LIMIT 100004
char stan_dfs[LIMIT+1];
int ojciec[LIMIT+1];
#include <stack>
void dfs (int n, // wierzcholki od 1 do n
          int startowy,
          bool skierowany = false) { // czy graf jest skierowany
   const char BIALY = 0, SZARY = 1, CZARNY = 2;
   memset(stan_dfs,BIALY,n+1);
   
   int i = startowy; {
      stack<pair<int,int> > kol;
      kol.push(mp(i,0));
      while (!kol.empty()) {
         int v = kol.top().first;
         int skad = kol.top().second;
         kol.pop();
                
         if (v < 0) {
            // wychodzimy z wierzcholka
            v = -v;
            
            vector<pair<long long,int> > fff;
            ll sumadr=0;
            FOREACH(it,adj[v]) if (*it != ojciec[v]) {
               fff.pb(mp(-pi[*it], *it));
               sumadr += dr[*it];
            }
            sort(ALL(fff));
            pi[v] = 0;
            if (v != startowy) {
               pi[v]++;
               beav[v]--;
            }
            int bierzemycalych = min(beav[v],(ll)fff.sz);
            FOR(j,bierzemycalych) {
               pi[v] += 1 - fff[j].fi;
               beav[v]--;
            }
            ll drugawycieczka = min(sumadr,beav[v]);
            pi[v] += 2*drugawycieczka;
            dr[v] = beav[v] - drugawycieczka;
            
            stan_dfs[v] = CZARNY;
            continue;
         }
         
         if (stan_dfs[v] == CZARNY) {
            // juz tu bylimy
            
            continue;
         }
         if (stan_dfs[v] == SZARY) {
            // mamy cykl: v <- skad <- ojciec[skad] <- ojciec[ojciec[skad]] <- ... <- v
            // w grafach nieskierowanych zostanie on zaraportowany dwa razy

         } else { // BIALY
            // odwiedzamy wierzcholek

            ojciec[v] = skad;
            stan_dfs[v] = SZARY;
            
            if (beav[v] == 0) {
               // useless!
               pi[v] = dr[v] = 0;
               continue;
            }

            if (adj[v].sz == 1 && v != startowy) {
               // lisc
//               printf("%d to lisc\n",v);
               pi[v] = 1;
               dr[v] = beav[v]-1;
            } else {
               kol.push(mp(-v,0));            
               for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
                  if (skierowany || (*it != skad)) { // w grafach nieskierowanych nie raportujemy naturalnych "cykli" a->b->a
                     kol.push(mp(*it,v));
                  }
               }
            }
         }
      }
   }
}


int main () {
   wez(n)
   FORI(i,n) {wez(x) beav[i]=x;}
   FORI(i,n-1) {
      wez2(x,y)
      adj[x].pb(y);
      adj[y].pb(x);
   }
   wez(s)
   dfs(n,s);
//   DBG(vi(pi+1,pi+n+1))
//   DBG(vi(dr+1,dr+n+1))
   cout << pi[s] << endl;
}
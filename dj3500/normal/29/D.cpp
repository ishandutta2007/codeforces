#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)2e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

int n;
vector<int> adj[301];
bool sciezka[301][301];
void czytaj_graf() {
   scanf("%d",&n);
   FORI(i,n) {
      FORI(j,n) {
         sciezka[i][j] = false;
      }
   }
   FOR(k,n-1) {
      int a,b;
      scanf("%d %d",&a,&b);
      adj[a].pb(b);
      adj[b].pb(a);
      sciezka[a][b] = sciezka[b][a] = true;
   }
}

vector<int> przesz_wszerz (int n, int i, int cel, vector<int> *adj) {
   vector<bool> odwiedzony(n+1,false);
   vector<int> ojciec(n+1, -1);
      deque<pair<int,int> > kol;
      kol.pb(mp(i,0));
      while (!kol.empty()) {
         int v = kol.front().first;
         int skad = kol.front().second;
         kol.pop_front();
         
         if (odwiedzony[v]) continue;
         odwiedzony[v] = true;
         ojciec[v] = skad;
         // odwiedzamy wierzcholek
         if (v == cel) {
            int x = v;
            vector<int> wynik;
            while (x != i) {
               wynik.pb(x);
               x = ojciec[x];
            }
            return wynik;
         }
         
         for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
            kol.pb(mp(*it,v));
         }
      }
}

int main () {
   czytaj_graf();
   int lisci = 0;
   for (int i = 2; i <= n; ++i) {
      if (adj[i].size() == 1) ++lisci;
   }

   int poprzedni = 1;
   vector<int> wynik;
   wynik.pb(1);
   
   FORI(lisc,lisci+1) {
      int obecny;
      if (lisc == lisci+1) {
         obecny = 1;
      } else {
         scanf("%d",&obecny);
      }
      
      vector<int> trasa = przesz_wszerz(n,poprzedni,obecny,adj);
      
      // przejdz od poprzedni do obecny
      //printf("\nide od %d do %d, trasa: ",poprzedni,obecny);
      //FOR(i,trasa.size()) printf("%d ",trasa[i]);
      
      trasa.pb(poprzedni);
      for (int i = trasa.size()-2; i >= 0; --i) {
         wynik.pb(trasa[i]);
         if (sciezka[trasa[i+1]][trasa[i]]) {
            sciezka[trasa[i+1]][trasa[i]] = false;
         } else {
            printf("-1\n");
            return 0;
         }
      }
      
      poprzedni = obecny;
   }
   
   FOR(i,wynik.size()) printf("%d ",wynik[i]);
        
   
}
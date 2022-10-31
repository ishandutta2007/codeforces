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

vi dwacol (int n, vi *adj) {
   vi ans(n+1,2);
   FORI(i,n) {
      if (ans[i] != 2) continue;
      deque<pii> q;
      q.pb(mp(i,0));
      while (!q.empty()) {
         int v = q.front().fi, kol = q.front().se;
         q.pop_front();
         if (ans[v] == 2) {
            ans[v] = kol;
            FOREACH(it,adj[v]) q.pb(mp(*it,1-kol));
         } else if (ans[v] != kol) return vi();
      }
   }
   return ans;
}

vi adj[100007];
int res[100007];

int main () {
   wez2(n,m)
   while(m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   FORI(i,n) res[i] = -1;
   vi col = dwacol(n,adj);
   int moc0 = 0;
   FORI(i,n) moc0 += (col[i] == 0);
   if (moc0 % 3 == 2) {
      FORI(i,n) col[i] = 1 - col[i];
      moc0 = n - moc0;
   }
   
   int kolor = 1;
   if (moc0 % 3 == 1) {
      bool ok = 0;
      // proba 1
      FORI(i,n) if (col[i] == 0) if (n-moc0-SZ(adj[i]) >= 2) {
         ok = 1;
         vector<bool> adjacentToI(n+1,0);
         FOREACH(x,adj[i]) adjacentToI[*x] = 1;
         vi nonAdjacent;
         FORI(j,n) if (col[j] == 1) if (!adjacentToI[j]) nonAdjacent.pb(j);
         // SZ(nonAdjacent) >= 2
         res[i] = 1;
         res[nonAdjacent[0]] = 1;
         res[nonAdjacent[1]] = 1;
         kolor = 2;
         break;
      }
      if (!ok) {
         // proba 2
         vi goodRights;
         FORI(j,n) if (col[j] == 1) if (moc0 - SZ(adj[j]) >= 2) goodRights.pb(j);
         if (SZ(goodRights) >= 2) {
            ok = 1;
            int g1 = goodRights[0], g2 = goodRights[1];
            vector<bool> adjacentToG1(n+1,0), adjacentToG2(n+1,0);
            FOREACH(x,adj[g1]) adjacentToG1[*x] = 1;
            FOREACH(x,adj[g2]) adjacentToG2[*x] = 1;
            vi nonAdjacentToG1, nonAdjacentToG2;
            FORI(i,n) if (col[i] == 0) if (!adjacentToG1[i]) nonAdjacentToG1.pb(i);
            FORI(i,n) if (col[i] == 0) if (!adjacentToG2[i]) nonAdjacentToG2.pb(i);
            res[g1] = res[nonAdjacentToG1[0]] = res[nonAdjacentToG1[1]] = 1;
            res[g2] = res[nonAdjacentToG2[0]] = res[nonAdjacentToG2[1]] = 2;
            kolor = 3;
         }
      }
      if (!ok) {
         printf("NO");
         return 0;
      }
   }
   // moc0 % 3 == 0
   vi nonColored[2];
   FORI(i,n) if (res[i] == -1) nonColored[col[i]].pb(i);
   FOR(u,2) for (int k = 0; k < SZ(nonColored[u]); k += 3) {
      res[nonColored[u][k]] = res[nonColored[u][k+1]] = res[nonColored[u][k+2]] = kolor;
      kolor++;
   }
   printf("YES\n");
   FORI(i,n) printf("%d ", res[i]);
}
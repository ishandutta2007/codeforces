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
using namespace std;
#define pb push_back
#define INF 2147483647
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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int ans[105];
vi adj[105];
int a[105],b[105];

bool niekoliduja (int a1, int b1, int a2, int b2) {
   if (b2 <= a1) return true;
   if (b1 <= a2) return true;
   if (a1 >= a2 && b1 <= b2) return true;
   if (a2 >= a1 && b2 <= b1) return true;
   return false;
}

// dwacol(n,adj) bierze graf o wierzchokach 0..n-1 (dla 1..n zmieni FOR na FORI) i go dwukoloruje
// jesli sie nie udalo, zamiast kolorowania zwraca pusty wektor
void dwacol_dfs (int v, int kolor, vi *adj, vi &ans, bool &fail) {
   if (ans[v] != 2) return;
   ans[v] = kolor;
   FOREACH(it,adj[v]) dwacol_dfs(*it, 1-kolor, adj, ans, fail);
   FOREACH(it,adj[v]) if (ans[*it] + ans[v] != 1) fail = 1;
}
vi dwacol (int n, vi *adj) {
   vi ans(n+1,2);
   bool fail = 0;
   FOR(i,n) dwacol_dfs(i,0,adj,ans,fail);
   if (fail) return vi();
   else return ans;
}

vi dwacol2 (int n, vi *adj) {
   vi ans(n+1,2);
   FOR(i,n) {
      deque<pii> q;
      q.pb(mp(i,0));
      while (!q.empty()) {
         int v = q.front().fi, kol = q.front().se;
         q.pop_front();
         if (ans[v] == 2) {
            ans[v] = kol;
            FOREACH(it,adj[v]) q.pb(mp(*it,1-kol));
         } else if (ans[v] != kol) return vi();
         // else: jest juz kolor i jest dobry
      }
   }
   return ans;
}
         

int main () {
   wez2(dupa,m)
   FOR(i,m) {
      wez2(aa,bb)
      a[i] = min(aa,bb);
      b[i] = max(aa,bb);
   }
   
   FOR(i,m) FOR(j,i) {
      if (niekoliduja(a[i],b[i],a[j],b[j])) continue;
      adj[i].pb(j);
      adj[j].pb(i);
   }
    
   vi ans = dwacol(m,adj);
   
   if (ans.empty()) {
      printf("Impossible\n");
      return 0;
   }
   
   FOR(i,m) printf(ans[i] ? "i" : "o");
}
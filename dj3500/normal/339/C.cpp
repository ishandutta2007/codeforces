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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 200007
int n; // input
vi adj[N]; // input
int dp[N]; // temp; -1 = unseen, -2 = processing, nonnegative = computed value
vi cycle;
int dpind[N];

void dfs (int v) {
	if (dp[v] == -2) {
	   cycle.pb(v);
	   throw 0;
	}
	try {
	   if (dp[v] != -1) return;
      dp[v] = -2;
      int best = 0, bestind = -1;
      FOREACH(x,adj[v]) {
         dfs(*x);
         if (1 + dp[*x] > best) {
            best = 1+dp[*x];
            bestind = *x;
         }
      }
      dp[v] = best;
      dpind[v] = bestind;
	} catch (int x) {
	   cycle.pb(v);
	   throw 0;
	}
}

int id[100][100], ostatni[N], roznica[N];

int main () {
   int nxtid = 1;
   REP(roz,-10,10) REP(ost,0,10) {
      int idd = nxtid++;
      id[roz+10][ost] = idd;      
      roznica[idd] = roz;
      ostatni[idd] = ost;
   }
   
   string mozna;
   cin >> mozna;
   int m;
   cin >> m;
   
   REP(roz,-10,10) REP(ost,0,10) {
      REP(nxt,1,10) if (mozna[nxt-1] == '1') if (ost != nxt) {
         if (roz <= 0) {
            // +
            int roz2 = roz + nxt;
            if (roz2 > 0) adj[id[roz+10][ost]].pb(id[roz2+10][nxt]);
         } else {
            // -
            int roz2 = roz - nxt;
            if (roz2 < 0) adj[id[roz+10][ost]].pb(id[roz2+10][nxt]);
         }
      }
   }
   n = nxtid - 1;
   
   FORI(i,n) dp[i] = -1;
   vi kol;
   //DBG(id[0+10][0]);
   try {
      dfs(id[0+10][0]);
      if (dp[id[0+10][0]] < m) {
         cout << "NO";
         return 0;
      } else {
         int v = id[0+10][0];
         kol.pb(v);
         FOR(k,m) {
            v = dpind[v];
            kol.pb(v);
         }
      }
   } catch (int x) {
      kol = cycle;
      reverse(ALL(kol));
      int ost = kol.back();
      int pos;
      FOR(i,SZ(kol)) if (ost == kol[i]) { pos = i; break; }
      int from = pos + 1, to = SZ(kol) - 1; // [from, to]
      int cur = from;
      while (SZ(kol) < m+1) {
         kol.pb(kol[cur++]);
         if (cur == to+1) cur = from;
      }
      while (SZ(kol) > m+1) kol.pop_back();
   }
   printf("YES\n");
   FOR(i,m) {
      printf("%d ", ostatni[kol[i+1]]);
   }
}
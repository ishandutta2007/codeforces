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
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int a[5005], ojc[5005], divpos[5005], traincap[5005], maxcap[5005], wyn[5005];
vector<pii> ve;
vector<pii> adj[5005];

int main () {
   wez(n)
   FORI(i,n) scanf("%d",a+i);
   FORI(i,n) ve.pb(mp(a[i],i));
   sort(ALL(ve));
   
   FOR(i,n-1) {
      wez3(v,u,c)
      adj[v].pb(mp(u,c));
      adj[u].pb(mp(v,c));
   }
   
   deque<pii> q;
   q.pb(mp(1,-1));
   while (!q.empty()) {
      int v = q.front().fi, skad = q.front().se;
      q.pop_front();
      ojc[v]=skad;
      FOREACH(it,adj[v]) {
         if (it->fi != skad) q.pb(mp(it->fi,v));
      }
   }
   
   FORI(i,n) {
      FOREACH(it,adj[i]) {
         if (it->fi == ojc[i]) maxcap[i] = it->se;
      }
   }
   
   wyn[1]=0;
   REP(i,2,n) wyn[i]=INF;
   FORI(i,n)divpos[i]=i;
   
   int turn = 0;
   while (1) {
      FORI(i,n) traincap[i]=0;
      
      int arr = 0;
      FOR(i,n) {
         int div = ve[i].se, city = divpos[div];
         if (city==1) {
            REMIN(wyn[div],turn)
            arr++;
            continue;
         }
         if (traincap[city]!=maxcap[city]) {
            traincap[city]++;
            divpos[div] = ojc[city];
         }
      }
      if (arr==n) break;
      ++turn;
      
   }
   FORI(i,n) printf("%d ",wyn[i]);
}
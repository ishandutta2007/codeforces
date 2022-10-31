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

#define N 100007
int arrivalTime[N], whatStop[N], gotOff[N], n, busCapacity, currentTime;

int main () {
   scanf("%d %d", &n, &busCapacity);
   set<pii> events;
   FORI(i,n) {
      scanf("%d %d", arrivalTime+i, whatStop+i);
      events.insert(mp(arrivalTime[i], i));
   }
   
   deque<int> q;
   bool busAtStop = 1;

   while (!events.empty()) {
      int what = events.begin()->se;
      currentTime = events.begin()->fi, 
      events.erase(events.begin());
      
      if (what != INF) {
         q.pb(what);
      } else {
         busAtStop = 1;
      }

      if (busAtStop && SZ(q) > 0) {
         if (SZ(q) >= busCapacity || currentTime >= arrivalTime[n]) {
            // depart
            busAtStop = 0;
            map<int,vi> m;
            int ppl = min(busCapacity, SZ(q));
            FOR(i,ppl) {
               int k = q.front();
               q.pop_front();
               if (!IN(whatStop[k], m)) m[whatStop[k]] = vi();
               m[whatStop[k]].pb(k);
            }
            int time = currentTime, position = 0;
            FOREACH(it,m) {
               time += it->fi - position;
               position = it->fi;
               FOREACH(x,it->se) {
                  gotOff[*x] = time;
               }
               time += 1 + SZ(it->se)/2;
            }
            time += position;
            events.insert(mp(time, INF));
         }
      }

   }
   
   FORI(i,n) printf("%d ", gotOff[i]);
}
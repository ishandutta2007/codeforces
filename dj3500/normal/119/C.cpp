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

#define N 105
ll a[N], b[N];
int c[N];

ll dp[64][64][128];
int mysubject[64][64][128], mydelta[64][64][128];

int main () {
   ios_base::sync_with_stdio(0);
   int n,m,k;
   cin >> n >> m >> k;
   FORI(i,m) {
      cin >> a[i] >> b[i] >> c[i];
   }

   FOR(i,64)FOR(j,64)FOR(u,128) dp[i][j][u] = 0;

   vi lower[105];
   FORI(sub,m) FORI(sub2,m) if (c[sub] < c[sub2]) lower[sub2].pb(sub);

   // day one
   FORI(subject,m) REP(delta,0,b[subject]-a[subject]) {
      dp[1][subject][delta] = delta+a[subject];
   }

   REP(day,2,n) FORI(subject,m) REP(delta,0,b[subject]-a[subject]) {
      ll tasks = a[subject] + delta;
      vector<ll> dobre;
      if (tasks > k) {
         dobre.pb(tasks-k);
      }
      if (tasks % k == 0) {
         dobre.pb(tasks/k);
      }
      FOR(u,SZ(dobre)) {
         ll prevtasks = dobre[u];
         FOR(g,SZ(lower[subject])) {
            int prevsubject = lower[subject][g];
            if (a[prevsubject] <= prevtasks && prevtasks <= b[prevsubject]) {
               int prevdelta = prevtasks - a[prevsubject];

               if (dp[day-1][prevsubject][prevdelta] == 0) continue;
               ll cand = tasks + dp[day-1][prevsubject][prevdelta];
               if (dp[day][subject][delta] < cand) {
                  dp[day][subject][delta] = cand;
                  mysubject[day][subject][delta] = prevsubject;
                  mydelta[day][subject][delta] = prevdelta;
               }
            }
         }
      }
   }

   // get result
   ll maxsumtasks = -1;
   int lastsubject, lastdelta;
   FORI(subject,m) REP(delta,0,b[subject]-a[subject]) {
      if (dp[n][subject][delta] > maxsumtasks) {
         maxsumtasks = dp[n][subject][delta];
         lastsubject = subject;
         lastdelta = delta;
      }
   }

   if (maxsumtasks <= 0) {
      cout << "NO" << endl;
   } else {
      cout << "YES" << endl;
      vector<pair<int,ll> > res;
      REPD(day,n,1) {
         res.pb(mp(lastsubject,a[lastsubject]+lastdelta));
         int lastsubject2 = mysubject[day][lastsubject][lastdelta];
         ll lastdelta2 = mydelta[day][lastsubject][lastdelta];
         lastsubject = lastsubject2;
         lastdelta = lastdelta2;
      }

      REPD(i,SZ(res)-1,0) cout << res[i].fi << " " << res[i].se << "\n";
   }
}
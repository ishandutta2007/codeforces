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
#include <cassert>
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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int main () {
   wez3(n,k,p)
   vi odd, even;
   FORI(i,n) {
      wez(x)
      if (x&1) odd.pb(x); else even.pb(x);
   }
   if (SZ(odd) < k-p || SZ(odd) % 2 != (k-p) % 2) {
      printf("NO");
   } else {
      if (p == 0) {
         printf("YES\n");
         FOR(i,k-p-1) printf("1 %d\n", odd[i]);
         printf("%d ", n - (k-p-1));
         REP(i,k-p-1,SZ(odd)-1) printf("%d ", odd[i]);
         FOREACH(it,even) printf("%d ", *it);
         return 0;
      }
      vector<vi> odds, evens;
      FOR(i,k-p) odds.pb(vi(1,odd[i]));
      for (int i = k-p; i < SZ(odd); i += 2) {
         vi nowy;
         nowy.pb(odd[i]);
         nowy.pb(odd[i+1]);
         evens.pb(nowy);
      }
      FOREACH(it,even) evens.pb(vi(1,*it));
      if (SZ(evens) < p) {
         printf("NO");
      } else {
         REP(i,p,SZ(evens)-1) evens[p-1].insert(evens[p-1].end(), ALL(evens[i]));
         
         printf("YES\n");
         FOREACH(it,odds) {
            printf("%d ", SZ((*it)));
            FOREACH(jt,(*it)) printf("%d ", *jt);
            printf("\n");
         }
         int e = 0;
         FOREACH(it,evens) {
            ++e;
            printf("%d ", SZ((*it)));
            FOREACH(jt,(*it)) printf("%d ", *jt);
            printf("\n");
            if (e == p) break;
         }
      }
   }
}
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

char name1[50],name2[50];

int main () {
   wez2(n,d)
   vector<pair<pair<string,string>,int> > v;
   while(n--) {
      int x;
      scanf(" %s %s %d",name1,name2,&x);
      v.pb(mp(mp(name1,name2),x));
   }
   
   set<pair<string,string> > res;
   FOREACH(x,v) {
      FOREACH(y,v) {
         if (x->fi.fi == y->fi.se &&
             x->fi.se == y->fi.fi &&
             x->se - y->se > 0 &&
             x->se - y->se <= d) {
                string s1 = x->fi.fi, s2 = x->fi.se;
                if (s1 > s2) swap(s1,s2);
                res.insert(mp(s1,s2));
             }
      }
   }
   
   pisz(SZ(res));
   FOREACH(x,res) {
      printf("%s %s\n", x->fi.c_str(), x->se.c_str());
   }
}
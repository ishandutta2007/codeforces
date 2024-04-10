#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

const int a231 = 1073741823;
map<int,int> m;
int h,q;

void add (int v, int e) {
   m[v] += e;
   if (v != 1) add(v/2,e);
}

int el(int v) {
   map<int,int>::iterator mi = m.find(v);
   if (mi==m.end()) return 0;
   else return mi->se;
}

double ex(int u, int v) {
   int elv=el(v);
   if (u >= elv) return u;
   if (v > a231) return elv; // max(u,elv) na mocy poprzedniej linijki
   int elv2=el(2*v);
   int elv21=el(2*v+1);
   double w;
   if (elv-elv21 >= elv21) {
      // el(L) + root >= el(R)
      w = 0.5 * max(u,elv-elv21);
      w += 0.5 * ex(max(elv-elv2,u), 2*v);
   } else {
      w = 0.5 * max(u,elv-elv2);
      w += 0.5 * ex(max(elv-elv21,u), 2*v+1);
   }
   return w;
}

double decay() {
   return ex(0,1);
}

int main () {
   ios_base::sync_with_stdio(0);
   cin >> h >> q;
   
   FOR(costam,q) {
      string s;
      cin >> s;
      if (s == "add") {
         int v,e;
         cin >> v >> e;
         add(v,e);
      } else {
         cout << setprecision(10) <<fixed << decay() << endl;
      }
   }
}
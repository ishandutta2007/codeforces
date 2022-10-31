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
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

#define pis pair<int,string>

string s[100002];
int a[100002];
int b[100002];

struct para {
   int fi;
   string se;
   
   para (int _fi, string _se) : fi(_fi), se(_se) { }
};

bool operator < (const para& p, const para &q) {
   if (p.fi != q.fi) return p.fi > q.fi;
   return p.se < q.se;
}
bool operator > (const para &p, const para &q) {
   if (p.fi != q.fi) return p.fi < q.fi;
   return p.se > q.se;
}
ostream& operator<<(ostream &s,para t) {return s<<"("<<t.fi<<","<<t.se<<")";}

vector<para> others;


int main () {
   int n;
   ios_base::sync_with_stdio(0);
   cin >> n;
   FOR(i,n) {
      cin >> s[i] >> a[i];
   }
   int m;
   cin >> m;
   FOR(i,m) {
      cin >> b[i];
   }
   sort(b,b+m,greater<int>());
   
   string vasya;
   int vasyapts;
   cin >> vasya;
   FOR(i,n) {
      if (s[i] == vasya) {
         vasyapts = a[i];
      } else {
         others.pb(para(a[i],s[i]));
      }
   }
   sort(ALL(others));
   //DBG(others)
   
   if (m == 0) {
      para vv(vasyapts,vasya);
      int better = 0;
      FOR(i,others.sz) {
         if (others[i] < vv) ++better;
      }
      cout << better+1 << " " << better+1 << endl;
      return 0;
   }
   
   // best place
   int vas = vasyapts + b[0];
   para vv(vas,vasya);
   int better = 0;
   FOR(i,others.sz) {
      if (others[i] < vv) ++better;
   }
   
   int rozdano = better+1;
   int zadobrzy = better;
   set<para> others2(ALL(others));
   FOR(i,zadobrzy) others2.erase(others2.begin());
   REP(rozdawana,rozdano,m-1) {
      set<para>::iterator it = others2.lower_bound(para(vas-b[rozdawana],vasya));
      if (it == others2.end()) {
         ++zadobrzy;
         others2.erase(others2.begin());
      } else {
         others2.erase(it);
      }
   }
   
   // worst place
   REP(i,m,n-1) b[i]=0;
   m=n;
   reverse(b,b+m); // na poczatku sa najmniejsze
   //DBG(vi(b,b+m))
   
   vas = vasyapts + b[0];
//   DBG(vas)
   vv = para(vas,vasya);
   better = 0;
   FOR(i,others.sz) {
      if (others[i] < vv) ++better;
   }
   
   rozdano = better+1;
   int zadobrzy2 = better;
   set<para,greater<para> > others3(ALL(others));
   FOR(i,zadobrzy2) {
      set<para,greater<para> >::iterator it = others3.end();
      --it;
//      printf("erasing %d,%s\n",it->fi, it->se.c_str());
      others3.erase(it);
   }
   REP(rozdawana,rozdano,m-1) {
      set<para,greater<para> >::iterator it = others3.upper_bound(para(vas-b[rozdawana],vasya));
      if (it == others3.end()) {
         others3.erase(others3.begin());
      } else {
         others3.erase(it);
         ++zadobrzy2;
      }
   }
   
   
   cout << zadobrzy + 1 << " " << zadobrzy2 + 1 << endl;
   
   
}
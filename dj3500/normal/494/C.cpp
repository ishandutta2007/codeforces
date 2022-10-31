// tested by Hightail: https://github.com/dj3500/hightail
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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int q;
typedef double real;

struct S {
   int maxx;
   double prob;
   vector<S*> children;
   
   vector<real> dp; // dp[y] = P(max[S] < maxx+y)
   // dp[0..q]
   
   // get(x) = P(max[S] < x)
   real get (int x) const {
      //if (x <= maxx) return 0.0;
      int y = x - maxx;
      if (y <= 0) return 0.0;
      if (y > q) return 1.0;
      return dp[y];
   }
   
   void go () {
      FOREACH(it,children) (*it)->go();
      vector<real> temp(q+1, 0.0);
      REP(y,1,q) {
         int x = y + maxx;
         temp[y] = 1.0;
         FOREACH(it,children) temp[y] *= (*it)->get(x);
      }
      dp.assign(q+1, 0.0);
      REP(y,1,q) {
         //int x = y + maxx;
         dp[y] = prob * temp[y-1] + (1 - prob) * temp[y];
      }
   }
   
   void wri () const {
      cout << "(" << maxx << "," << prob << ",[";
      FOREACH(it,children) {
         (*it)->wri();
         cout << ",";
      }
      cout << "])";
   }
};

const int N = 100007;
int a[N];
vector<S> storage;
bool operator < (const pair<int,S*> &A, const pair<int,S*> &b) { return A.fi < b.fi; }

int main () {
   wez(n)
   scanf("%d", &q);
   FORI(i,n) scanf("%d", a+i);
   vector<pair<int,pair<pii,double> > > v;
   FOR(u,q) {
      wez2(l,r)
      double p;
      scanf("%lf", &p);
      v.pb(mp(r-l,mp(mp(l,r),p)));
   }
   v.pb(mp(n-1,mp(mp(1,n),0.0)));
   ++q;
   sort(ALL(v));
   
   set<pair<int,S*> > st;
   FORI(i,n) {
      st.insert(mp(i,(S*)0));//-1));
   }
   
   FOREACH(it,v) {
      int l = it->se.fi.fi, r = it->se.fi.se;
      double p = it->se.se;
      S *s = new S();
      s->prob = p;
      s->maxx = -1;
      set<pair<int,S*> >::iterator i;
      for (i = st.lower_bound(mp(l,(S*)0)); i != st.end() && i->fi <= r; ++i){
         if (i->se == 0) {
            REMAX(s->maxx, a[i->fi]);
         } else {
            s->children.pb(i->se);
            REMAX(s->maxx, i->se->maxx);
         }
      }
      st.erase(st.lower_bound(mp(l,(S*)0)), i);
      st.insert(mp(l, s));
   }
   
   assert(SZ(st) == 1);
   S *root = st.begin()->se;
   //st.begin()->se->wri();
   root->go();
   int maxx = root->maxx;
   real res = 0;
   REP(x,maxx,maxx+q) {
      //DBG(x)
      res += x * (root->get(x+1) - root->get(x));
      //DBG(root->get(x+1))
      //DBG(root->get(x));
   }
   //DBG(res)
   //DBG(root->dp);
   cout << setprecision(13) << fixed << res;
   //printf("%.13lf\n", double(res));
}
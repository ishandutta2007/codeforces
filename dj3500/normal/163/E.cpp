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

bool active[100007];

// struktura do szukania wielu wzorcow naraz w czasie liniowym
// uzycie: pare razy addWord(s), potem calcLink(), potem searchAll lub searchFirst
struct mkmp {
   struct leaf {
      map<char,leaf*> son;
      leaf *lnk, *wo;
      int el;
      int ile;
      leaf() : el(-1), ile(0) {}
   };

   vi len;
   leaf root;
   vector<leaf*> wskaznik[100007]; // ...

   leaf* mv(leaf *w, char l) {
      while (w != &root && !IN(l,w->son)) w= w->lnk;
      if (IN(l,w->son)) w = w->son[l];
      return w;
   }

   int addWord (const char *s) {
      int l = strlen(s);
      leaf *p = &root;
      for (; *s; ++s) {
         map<char,leaf*>::iterator e = p->son.find(*s);
         p = (e == p->son.end()) ? p->son[*s] = new leaf : e->se;
      }
      if (p->el == -1) {
         p->el = SZ(len);
         len.pb(l);
      }
      return p->el;
   }

   void calcLink() {
      vector<leaf*> l;
      leaf *w;
      root.lnk = root.wo = 0;
      FOREACH(it,root.son) {
         l.pb(it->se);
         it->se->lnk = &root;
      }
      FOR(x,SZ(l)) {
         l[x]->wo = (l[x]->lnk->el != -1) ? l[x]->lnk : l[x]->lnk->wo;
         FOREACH(it,l[x]->son) {
            l.pb(it->se);
            w = l[x]->lnk;
            w = mv(w,it->fi);
            it->se->lnk = w;
         }
      }
   }

   // znajduje wszystkie wystapienia kazdego wzorca, wynik: {<pozycja, nr wzorca>}
ll searchAll(const char *s) {
      ll ans = 0;
      leaf *p = &root;//, *r;
      for (int x = 0; s[x]; ++x) {
         p = mv(p, s[x]);
         //for (r = p; r; r = r->wo) {
         //   if (active[r->el + 1]) ++ans;
         //}
         ans += p->ile;
      }
      return ans;
   }
   
   void dfs (leaf *p) {
      p->ile = 0;
      for (leaf *r = p; r; r = r->wo) {
         if (r->el != -1) {
            ++p->ile;
            wskaznik[r->el + 1].pb(p);
         }
      }
      // recurse
      FOREACH(it,p->son) dfs(it->se);
   }
};

char s[1000007];

int main () {
   mkmp ac;
   wez2(n,k)
   active[0] = 0;
   FORI(i,k) {
      active[i] = 1;
      scanf("%s",s);
      ac.addWord(s);
   }
   ac.calcLink();
   ac.dfs(&(ac.root));
   while(n--) {
      scanf(" %s",s);
      if (s[0] == '+') {
         int x = atoi(s+1);
         if (active[x] == 0) {
            active[x] = 1;
            //
            FOREACH(it,ac.wskaznik[x]) (*it)->ile++;
         }
      } else if (s[0] == '-') {
         int x = atoi(s+1);
         if (active[x] == 1) {
            active[x] = 0;
            //
            FOREACH(it,ac.wskaznik[x]) (*it)->ile--;
         }
      } else {
         printf("%I64d\n", ac.searchAll(s+1));
      }
   }
}
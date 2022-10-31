#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cout << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (__typeof((t).begin()) i = (t).begin(); i != (t).end(); ++i)
#define fi first
#define se second

const ll INF = 1LL<<61;


struct StaticHull : vector<pair<double,pair<ll,ll> > > {
   void add (ll a, ll b) {
      if (empty()) return pb(mp(-INF, mp(a,b)));
      if (back().se.fi == a)  {
         if (back().se.se >= b) return;
         pop_back();
         return add(a,b);
      }
      assert(back().se.fi < a);
      #define PRZ (1.0 * (b - back().se.se) / (back().se.fi - a))
      while (back().fi >= PRZ) pop_back();
      pb(mp(PRZ,mp(a,b)));
   }
   ll eval (ll x) {
      if (empty()) return -INF;
      pair<ll,ll> ab = (lower_bound(begin(), end(), mp(1.0*x,ab)) - 1)->se;
      return ab.fi * x + ab.se;
   }

   pair<ll,ll> eval2 (double x) {
      return (lower_bound(begin(), end(), mp(x,mp(0LL,0LL))) - 1)->se;
   }
};

bool cmpA;
struct Line { // ax+b. xl = x-owa wspolrzedna przeciecia z poprzednia prosta w secie
   ll a, b;
   mutable long double xl; // ustawiane wylacznie przez add, czytane wylacznie przez eval
   bool operator < (const Line &l) const { if (cmpA) return a < l.a; else return xl < l.xl; }
};
struct DynamicHull : multiset<Line> {
   // jak nie ma C++0x:
   iterator prev (iterator y) { return --y; }
   iterator next (iterator y) { return ++y; }

   bool bad (iterator y) {
      iterator z = next(y), x;
      if (y == begin()) {
         if (z == end()) return 0; // jedyny -> dobry
         // dobry, chyba ze ten kolejny jest rownolegly i nad nim
         return y->a == z->a && y->b <= z->b;
      }
      x = prev(y);
      if (z == end()) {
         // dobry, chyba ze ten poprzedni jest rownolegly i nad nim
         return y->a == x->a && y->b <= x->b;
      }
      // ma obu sasiadow
      return 1.0L * (x->b - y->b) * (z->a - y->a) >= 1.0L * (y->b - z->b) * (y->a - x->a);
   }

   // niezmiennik: a rosnie ostro, xl tez
   void add (ll a, ll b) {
      cmpA = 1;
      iterator y = insert((Line){a,b,-INF});
      if (bad(y)) { erase(y); return; }
      while (next(y) != end() && bad(next(y))) erase(next(y));
      while (y != begin() && bad(prev(y))) erase(prev(y));
      if (next(y) != end()) next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
      if (y != begin()) y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
   }

   ll eval (ll x) {
      if (empty()) return -INF;
      cmpA = 0;
      iterator it = prev(lower_bound((Line){0,0,1.0L*x}));
      return it->a * x + it->b;
   }

   pair<ll,ll> eval2 (double x) {
      cmpA = 0;
      iterator it = prev(lower_bound((Line){0,0,1.0L*x}));
      return mp(it->a, it->b);
   }
};

// zadania testowe:
// tylko dynamic:
//    WF2011 F
// oba:
//   COCI 2011/12 #3 TRAKA
//   Autostrady z AMPPZ 2013 (na MAINie) (nie trzeba, ale mozna miec szybciej za pomoca tego)

/*int main () {
   int te = 0;
   while(1) {
      int n,C,D;
      scanf("%d %d %d", &n, &C, &D);
      if (n == 0) return 0;
      map<int,vector<pair<pii,int> > > mapa;
      mapa[D+1]; // :)
      ll M = C;
      while (n--) {
         int Di,Pi,Ri,Gi;
         scanf("%d %d %d %d", &Di, &Pi, &Ri, &Gi);
         mapa[Di].pb(mp(mp(Pi,Ri),Gi));
      }
      DynamicHull ot;
      FOREACH(it,mapa) {
         int Di = it->fi;
         M = max(M, ot.eval(Di));
         FOREACH(i,it->se) {
            int Pi = i->fi.fi, Ri = i->fi.se, Gi = i->se;
            if (M >= Pi) {
               ll fi = M - Pi + Ri - 1LL * Gi * (Di + 1);
               ot.add(Gi,fi);
            }
         }
      }
      printf("Case %d: %lld\n", ++te, M);
   }
}*/

/*#define N 100007
int t[N], f[N];
int g[N]; // prefsuma t

int main () {
   int n,m;
   scanf("%d %d", &n, &m);
   FORI(i,n) scanf("%d", t+i);
   FORI(i,n) g[i] = g[i-1] + t[i];
   FORI(j,m) scanf("%d", f+j);

   DynamicHull ot;
   //vector<pii> sorter;
   //FOR(i,n) sorter.pb(mp(g[i], t[i+1]));
   //sort(sorter.begin(), sorter.end());
   //FOREACH(it,sorter) ot.add(it->fi, it->se);
   FOR(i,n) ot.add(g[i], t[i+1]);

   ll s = 0;
   REP(j,1,m) {
      int x1 = f[j] - f[j+1], x2 = f[j];
      pair<ll,ll> opt = ot.eval2(1.0 * x1 / x2);
      s += opt.fi * x1 + opt.se * x2;
   }
   //s += 1LL * f[m] * g[n];
   printf("%lld", s);
}
*/

#define N 100007
int a[N], b[N];
ll dp[N];

int main () {
   int n;
   scanf("%d", &n);
   FORI(i,n) scanf("%d", a+i);
   FORI(i,n) scanf("%d", b+i);
   DynamicHull ot;
   REPD(i,n,1) {
      if (i == n) {
         dp[n] = 0;
      } else {
         dp[i] = -ot.eval(b[i]);
      }
      ot.add(-a[i], -dp[i]);
   }
   cout << dp[1];
}
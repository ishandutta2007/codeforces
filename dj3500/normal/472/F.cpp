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
#include <bitset>
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
#define DBG(vari) //cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vector<pii> Res;

int GaussZ2 (vector<int> &equ) {
   int n = SZ(equ), a = 0, b = 0, c;
   const int s = 30;
   for ( ; a < n && b < s; ++b) {
      for (c = a; c < n && !(equ[c] & (1<<b)); ++c);
      if (c < n) {
         if (a != c) {
            equ[a] ^= equ[c];
            Res.pb(mp(a,c));
         }
         FOR(y,n) if (a != y && (equ[y] & (1<<b))) {
            equ[y] ^= equ[a];
            Res.pb(mp(y,a));
         }
         ++a;
         //DBG(b)
      }
   }
   return a;
}

template <size_t s> int gg (vector<bitset<s> > equ, vi vals, vi &res) {
   int n = SZ(equ), a = 0, b = 0, c;
   res.resize(s, 0);
   for ( ; a < n && b < s; ++b) {
      for (c = a; c < n && !equ[c][b]; ++c);
      if (c < n) {
         if (a != c) { equ[a] ^= equ[c]; vals[a] ^= vals[c]; }
         FOR(y,n) if (a != y && equ[y][b]) { equ[y] ^= equ[a]; vals[y] ^= vals[a]; }
         res[b] = ++a;
      }
   }
   FOR(x,b) if (res[x]) res[x] = vals[res[x] - 1];
   FOR(x,n) {
      c = 0;
      FOR(z,s) if (equ[x][z]) c ^= res[z];
      if (c != vals[x]) { printf("-1"); exit(0); }
   }
   return s-a;
}

vi x;
int a;
vi wsp (int num) {
   vector<bitset<30> > equ;
   vi vals, res;
   FOR(b,30) {
      bitset<30> bs;
      FOR(i,a) bs[i] = !!((1<<b) & x[i]);
      equ.pb(bs);
      vals.pb(!!((1<<b) & num));
   }
   //DBG(equ)
   //DBG(vals)
   gg(equ, vals, res);
   //DBG(res)
   return res;
}

int main () {
   wez(n)
   vi y(n);
   x.assign(n,0);
   FOR(i,n) { scanf("%d", &x[i]); }
   FOR(i,n) { scanf("%d", &y[i]); }
   a = GaussZ2(x);
   
   DBG(Res)DBG(x)DBG(a)
   
   for (int i = a; i < n; ++i) {
      vi res = wsp(y[i]);
      FOR(k,a) if (res[k]) Res.pb(mp(i,k));
   }
   
   set<int> undone;
   FOR(i,a) undone.insert(i);
   while (!undone.empty()) {
      vector<bool> needed(a,0);
      bool found = 0;
      FOREACH(ii,undone) {
         const int i = *ii;
         vi res = wsp(y[i]);          DBG(i)DBG(res)
         if (res[i]) {
            //printf("%d uzywa sam siebie\n", i);
            found = 1;
            FOR(k,a) if (res[k] && k != i) Res.pb(mp(i,k));
            x[i] = y[i];
            undone.erase(i);
            break;
         }
         FOR(k,a) if (res[k]) needed[k] = 1;
      }
      if (found) {
         // ok
      } else {
         // moze ktorys jest nieuzywany przez nikogo
         FOREACH(ii,undone) {
            const int i = *ii;
            if (!needed[i]) {
               //printf("%d jest nieuzywany\n", i);
               // zrob i
               found = 1;
               vi res = wsp(y[i]);
               Res.pb(mp(i,i));
               FOR(k,a) if (res[k] && k != i) Res.pb(mp(i,k));
               x[i] = y[i];
               undone.erase(i);
               break;
            }
         }
         if (found) continue;
         
         vi vec(ALL(undone));
         FOR(fff,5) {
            int i = vec[rand() % SZ(vec)], j = vec[rand() % SZ(vec)];
            if (i != j) {
               x[i] ^= x[j];
               Res.pb(mp(i,j));
            }
         }
      }
   }
   
   pisz(SZ(Res));
   FOREACH(it,Res) printf("%d %d\n", it->fi + 1, it->se + 1);
}